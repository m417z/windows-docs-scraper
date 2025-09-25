# NDK_VERSION structure

## Description

The **NDK_VERSION** structure specifies major and minor versions in the NDK interface.

## Members

### `Major`

The NDK major version number.

### `Minor`

The NDK minor version number.

## Remarks

This structure is used to specify NDK version numbers in several NDK structures and functions.

To specify version 1.1 (for Windows Server 2012), set both the **Major** and **Minor** members to 1.

To specify version 1.2 (for Windows Server 2012 R2), set the **Major** member to 1 and the **Minor** member to 2.

## See also

[NDIS_OPEN_NDK_ADAPTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndisndk/ns-ndisndk-_ndis_open_ndk_adapter_parameters)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/ns-ndkpi-_ndk_object_header)