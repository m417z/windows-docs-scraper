# _NDIS_NDK_PROVIDER_CHARACTERISTICS structure

## Description

The **NDIS_NDK_PROVIDER_CHARACTERISTICS** structure specifies NDK provider characteristics.

## Members

### `Header`

An
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that describes this
**NDIS_NDK_PROVIDER_CHARACTERISTICS** structure. NDIS sets the members of the **NDIS_OBJECT_HEADER** structure as follows:

* NDIS sets the **Type** member to **NDIS_OBJECT_TYPE_NDK_PROVIDER_CHARACTERISTICS**.
* NDIS sets the **Revision** member to **NDIS_NDK_PROVIDER_CHARACTERISTICS_REVISION_1**.
* NDIS sets the **Size** member to **NDIS_SIZEOF_NDK_PROVIDER_CHARACTERISTICS_REVISION_1**.

### `Flags`

Reserved, must be set to zero.

### `OpenNDKAdapterHandler`

The entry point for the [OPEN_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-open_ndk_adapter_handler) function.

### `CloseNDKAdapterHandler`

The entry point for the [CLOSE_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-close_ndk_adapter_handler) function.

## Remarks

To specify entry points for NDK services and other NDK provider characteristics, NDIS miniport drivers pass a pointer to an initialized **NDIS_NDK_PROVIDER_CHARACTERISTICS** structure to the [NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.

## See also

[CLOSE_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-close_ndk_adapter_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[OPEN_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-open_ndk_adapter_handler)