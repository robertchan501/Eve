#include <runtime.h>

typedef value *registers;

typedef struct variable {
    estring name;
    register dest;
    vector objects;
} *variable;


typedef closure cardinality_handler(u64 count);
typedef closure checker(variable v, registers r);

typedef struct object {
    variable self;
    vector attributes;
    multibag scopes;
    checker check;
    void (*cardinality)(object obj, variable v, cardinality_handler);
    void (*produce)(block bk, object obj, registers, variable v);
} *object;

typedef struct attribute {
    estring name;
    variable free; // avoiding dynamic typing
    value v;
} *attributes;


static void produce_result(object producer, block bk, registers r, variable v)
{
    vector_foreach(v->objects, i) {
        object obj = i;
        if (i != producer) {
            // this check can be cheaper than the generic cardinality report
            if (!obj->cardinality(obj, v, r)) return;
        }
    }
    generic_join_step(bk, r);
}



// synchronous today - one variable only, i think there
// are some other interesting possibilities
static void edb_produce(object obj, registers r, variable v, proudction_result result)
{
    if (bound(r, obj->self)) {
    } else {
    }
    apply(result);
}

// if i asked you my object, right now, given whats already bound, what
// the worst case estimate of the card of V is
static void generic_join_step(block bk, registers r)
{
    // think about a multi-attribute join decision
    // here we are selecting
    u64 variable_set = -1ull;
    object lowest_object;
    variable lowest_variable;
    u64 min_cost = -1ull;

    foreach_bit(variable_set, 64, i) {
        variable v = bk->variables[i]->objects;
        vector_foreach(v->objects, obj) {
            u64 cost = object_variable_cost(obj, v, r);
            if (n < min) {
                best = v->attribute;
                min = n;
            }
        }
    }

    object->produce(bk, obj, r) {
    }
}

static int object_production(object obj, registers r, variable v, execf next)
{
    multibag_foreach_eAv(obj, e, v->a, v) {
        register_set(v->dest, e);
        register_set(v->dest, v);
    }

}

static int object_v_production(object obj, registers r, register entity, variable v, execf next)
{
    multibag_foreach_v(obj, lookup(r, entity), lookup(r, v->register), v) {
        register_set(v->dest, e);
        register_set(v->dest, v);
    }
}

void execute_block(block bk)
{
    u64 min = -1ull;
    vector_foreach(bk->objects, obj) {
        u64 n = object_cardinality(obj);
        // in the distributed case, we cant determine this
        // unless all of the relevant scopes are local
        if (n == 0) {
            // a better exit?
            return;
        }
        if (n < min) {
            n = min;
            object = n;
        }
    }
}


// at the moment the graph is rooted in the object with entity e
block build_hypergraph(edb h, uuid e)
{

    edb_foreach_av(e, ) {

    }
}
