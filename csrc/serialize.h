/* there should be a 'this' uuid for container metadata..files and connections */

/*
 * note on denormal numbers - highest 11 bits are zero
 */

#define type_uuid 0x80
#define type_string 0x40

#define station_prefix 0x06
#define ignore_constant 0x05
#define register_prefix 0x04
#define float64_prefix  0x03
#define true_constant    0x02
#define false_constant   0x01

// also compressed strings please

static inline int first_bit_set(u64 value)
{
    return(63-__builtin_clzll(value));
}

static inline u64 mask(int x)
{
    return((1<<x) -1);
}

static inline byte bitstring_extract(u64 source, int highest_start, int bits)
{
    int x = highest_start - bits;
    if (x < 0) x = 0;
    return (source >> x) & ((1<<bits) -1);
}


static CONTINUATION_3_1(fill_bag, edb, value *, value *, value);
static void fill_bag(edb target, value *e, value *a, value v)
{
    if (!*e) {*e = v; return;}
    if (!*a) {*a = v; return;}
    edb_insert(target, *e, *a, v, 0);
    *e = *a = 0;
}

buffer_handler allocate_deserialize(heap h, closure(handler, value));

static inline buffer_handler deserialize_into_bag(heap h, edb b)
{
    value *e = allocate(h, sizeof(value));
    value *a = allocate(h, sizeof(value));
    *e = *a = 0;
    return(allocate_deserialize(h, cont(h, fill_bag, b, e, a)));
}
void serialize_edb(buffer dest, edb db);
