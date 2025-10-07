enum RAY_FLAG : uint
{
    RAY_FLAG_NONE                            = 0x00,
    RAY_FLAG_FORCE_OPAQUE                    = 0x01,
    RAY_FLAG_FORCE_NON_OPAQUE                = 0x02,
    RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH = 0x04,
    RAY_FLAG_SKIP_CLOSEST_HIT_SHADER         = 0x08,
    RAY_FLAG_CULL_BACK_FACING_TRIANGLES      = 0x10,
    RAY_FLAG_CULL_FRONT_FACING_TRIANGLES     = 0x20,
    RAY_FLAG_CULL_OPAQUE                     = 0x40,
    RAY_FLAG_CULL_NON_OPAQUE                 = 0x80,
    RAY_FLAG_SKIP_TRIANGLES                  = 0x100,
    RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES      = 0x200,
};