#include <runtime.h>

typedef value *registers;

typedef struct variable {
    estring name;
    register dest;
    vector objects;
} *variable;

typedef struct object {
    variable self;
    vector attributes;
    multibag scopes;
    // synch cardino, asynch burpo
    u64 (*cardino)();
    void (*)burpo))(vector terms, registers);
} *object;

typedef struct attribute {
    estring name;
    variable free; // avoiding dynamic typing
    value v;
} *attributes;


// if i asked you my object, right now, given whats already bound, what
// the worst case estimate of the card of V is
static int object_cardinality(multibag scopes, object obj, registers r, variable v)
{
    // think about a multi-attribute join decision
    // here we are selecting 
    u64 min = -1ull;
    foreach(obj->attributes, a) {
        u64 n;
        variable best;
        
        if (a->free) {
            if (!bound(r, a->free)){
                if ((n = multibag_cardinality(s_eAv, 0, a->name, 0))) {
                    /* if we have all the scopes in hand, its worth
                     * querying here against the bound values
                     * to get a better cardinality estimate 
                     */
                    if (n < min) {
                        best = v->attribute;
                        min = n;
                    }
                }
            }
        }
    }
    *v = best;
    return min;
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
