# D2D1_PATCH_EDGE_MODE enumeration

## Description

Specifies how to render gradient mesh edges.

## Constants

### `D2D1_PATCH_EDGE_MODE_ALIASED:0`

Render this patch edge aliased. Use this value for the internal edges of your gradient mesh.

### `D2D1_PATCH_EDGE_MODE_ANTIALIASED:1`

Render this patch edge antialiased. Use this value for the external (boundary) edges of your mesh.

### `D2D1_PATCH_EDGE_MODE_ALIASED_INFLATED:2`

Render this patch edge aliased and also slightly inflated. Use this for the internal edges of your gradient mesh when there could be t-junctions among patches.
Inflating the internal edges mitigates seams that can appear along those junctions.

### `D2D1_PATCH_EDGE_MODE_FORCE_DWORD:0xffffffff`