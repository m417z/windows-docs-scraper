# D3D10DDI_VERTEX_CACHE_DESC structure

## Description

The D3D10DDI_VERTEX_CACHE_DESC structure describes mesh-optimization data.

## Members

### `Pattern` [out]

The bit pattern. The driver must specify the bit pattern as a CACH four-character code (FOURCC) value. The driver can use the following MAKEFOURCC macro to specify the FOURCC value as CACH:

```cpp
MAKEFOURCC('C', 'A', 'C', 'H');
```

### `OptMethod` [out]

The method of mesh optimization. The driver can use one of the following values to specify the mesh optimization that it uses.

|Value|Meaning|
|--- |--- |
|0|Longest strips optimization|
|1|Vertex-cache-based optimization|

### `CacheSize` [out]

The effective size, in entries, that the driver optimizes the vertex cache for. The actual cache size is not required to be the size that is specified in **CacheSize** because the actual cache size is larger in most situations. The driver specifies an optimized size in **CacheSize** only if it also specifies 1 in the **OptMethod** member.

### `MagicNumber` [out]

The number that should be used as part of a trial-and-error procedure when you are determining when to restart the strips list. This number can be from 1 through the value that is specified in the **CacheSize** member. Typically, the best values are near **CacheSize**/2. The driver specifies a number in **MagicNumber** only if it also specifies 0 in the **OptMethod** member.