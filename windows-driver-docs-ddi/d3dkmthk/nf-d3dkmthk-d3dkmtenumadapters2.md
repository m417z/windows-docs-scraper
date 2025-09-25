# D3DKMTEnumAdapters2 function

## Description

The **D3DKMTEnumAdapters2** function supplies information for enumerating all graphics and display adapters on the system.

## Parameters

### `unnamedParam1`

[in, out] Pointer to a [**D3DKMT_ENUMADAPTERS2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters2) structure in which to supply information about adapters on the system. See Remarks.

## Return value

**D3DKMTEnumAdapters2** returns STATUS_SUCCESS upon success or an error such as one of the following.

| Return Code | Description |
| ----------- | ----------- |
| STATUS_BUFFER_TOO_SMALL | The provided array is too small to receive all the adapters. |
| STATUS_INVALID_PARAMETER | **pAdapters** is NULL or is otherwise an invalid memory region. |
| STATUS_NO_MEMORY | Memory cannot be allocated to satisfy the operation. |

## Remarks

On input, [**NumAdapters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters2) specifies how many adapters can be returned in the empty array that **pAdapters** points to. On return, if **D3DKMT_ENUMADAPTERS2** returns STATUS_SUCCESS:

* If **pAdapters** is non-NULL, **NumAdapters** will contain the number of adapters returned in the **pAdapters** array.
* If **pAdapters** is NULL, **NumAdapters** will contain the maximum supported adapter count.

If **D3DKMT_ENUMADAPTERS2** returns an error, **NumAdapters** is undefined.

**D3DKMTEnumAdapters2** is typically called twice:

* For the first call, set **pAdapters** to NULL. **D3DKMTEnumAdapters2** will write the maximum supported adapter count in [**NumAdapters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters2).

* For the second call, set **NumAdapters** to the value returned in the first call and set **pAdapters** to point to an array of **NumAdapters** [**D3DKMT_ENUMADAPTERS2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters2) structures. **D3DKMTEnumAdapters2** will fill in the array and pass back the number of array structures (adapters) that it filled.

Once the caller of **D3DKMTEnumAdapters2** has successfully received an enumeration of the adapters, it is the caller's responsibility to manage the lifespan of the adapter D3DKMT_HANDLEs. These handles are returned through **pAdapters**, and they must be closed with [**D3DKMTCloseAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcloseadapter).

## See also

[**D3DKMT_ENUMADAPTERS2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_enumadapters2)

[**PFND3DKMT_ENUMADAPTERS2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_enumadapters2)

[**D3DKMTCloseAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcloseadapter)