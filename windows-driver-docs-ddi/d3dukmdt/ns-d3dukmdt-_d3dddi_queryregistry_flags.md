# D3DDDI_QUERYREGISTRY_FLAGS structure

## Description

These flags control how strings are being retrieved through [**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2) for **D3DDDI_QUERYADAPTERTYPE_QUERYREGISTRY**.

## Members

### `TranslatePath`

**TranslatePath** is meant for use by the caller from a virtual machine. This flag is ignored if a call is made from a non-virtualized environment. For more information, see [GPU para-virtualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization).

When a particular registry key stores a path to another driver file, the caller of [**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2) might have that path translated into the path that an isolated processes can access. Setting **TranslatePath** to 1 indicates the registry key is a string that should be translated, when appropriate.

When this flag is set, [**D3DDDI_QUERYREGISTRY_INFO::ValueType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_queryregistry_info) must be `REG_SZ`, `REG_MULTI_SZ`, or `REG_EXPAND_SZ` and the value string is processed to translate the path to the virtual machine space. The translation only happens when the **OutputString** is an absolute path to a file in the DriverStore folder. The path is translated to `:\windows\system32\HostDriverStore\...`.

Set the flag only when **D3DDDI_QUERYREGISTRY_INFO::QueryType** is **D3DDDI_QUERYREGISTRY_SERVICEKEY** or **D3DDDI_QUERYREGISTRY_ADAPTERKEY**.

The registry string must be a full path to a file in the driver store. Translation won't occur when translation isn't needed.

**TranslatePath** must be set to 0 when [**D3DDDI_QUERYREGISTRY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_queryregistry_info)**::D3DDDI_QUERYREGISTRY_DRIVERSTOREPATH** and **D3DDDI_QUERYREGISTRY_DRIVERIMAGEPATH** are used.
However, **D3DDDI_QUERYREGISTRY_DRIVERSTOREPATH** and **D3DDDI_QUERYREGISTRY_DRIVERIMAGEPATH** will always act as if **TranslatePath** were set to 1.

### `MutableValue`

Reserved. Callers of **pfnQueryAdapterInfoCb2** must set this value to 0.

### `Reserved`

Reserved. Callers of **pfnQueryAdapterInfoCb2** must set this value to 0.

### Value

The **Value** field exists to read all these flags in a raw syntax, instead of the named bitfield.

## See also

[**D3DDDI_QUERYREGISTRY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_queryregistry_info)

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)