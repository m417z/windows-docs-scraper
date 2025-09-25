## Description

A **KMTQUERYADAPTERINFOTYPE** value indicates the specific [**Type**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo) of adapter information being retrieved by [**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo).

## Constants

### `KMTQAITYPE_UMDRIVERPRIVATE`

The buffer that **pPrivateDriverData** points to is populated with private driver data in a vendor-specific format. To read and process the private data, a tight coupling between the user-mode driver (UMD) and the kernel-mode display miniport driver (KMD) must exist.

### `KMTQAITYPE_UMDRIVERNAME`

The **pPrivateDriverData** member points to a [**D3DKMT_UMDFILENAMEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_umdfilenameinfo) structure that is filled with the name of the UMD.

### `KMTQAITYPE_UMOPENGLINFO`

**pPrivateDriverData** points to a [**D3DKMT_OPENGLINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openglinfo) structure that contains information about the OpenGL ICD. Non-DirectX applications can use this name to call the OpenGL ICD directly, although such usage is not recommended.

### `KMTQAITYPE_GETSEGMENTSIZE`

**pPrivateDriverData** points to a [**D3DKMT_SEGMENTSIZEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_segmentsizeinfo) structure that contains information about the size of memory and aperture segments.

### `KMTQAITYPE_ADAPTERGUID`

**pPrivateDriverData** points to a variable that contains the GUID for the adapter.

### `KMTQAITYPE_FLIPQUEUEINFO`

**pPrivateDriverData** points to a [**D3DKMT_FLIPQUEUEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipqueueinfo) structure that contains information about the queue of flip operations.

### `KMTQAITYPE_ADAPTERADDRESS`

**pPrivateDriverData** points to a [**D3DKMT_ADAPTERADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapteraddress) structure that contains information about the physical location on the PCI bus of the adapter.

### `KMTQAITYPE_SETWORKINGSETINFO`

**pPrivateDriverData** points to a [**D3DKMT_WORKINGSETINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_workingsetinfo) structure that contains information about the working set.

### `KMTQAITYPE_ADAPTERREGISTRYINFO`

**pPrivateDriverData** points to a [**D3DKMT_ADAPTERREGISTRYINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapterregistryinfo) structure that contains registry information about the graphics adapter.

### `KMTQAITYPE_CURRENTDISPLAYMODE`

**pPrivateDriverData** points to a [**D3DKMT_CURRENTDISPLAYMODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_currentdisplaymode) structure that contains the current display mode.

### `KMTQAITYPE_MODELIST`

**pPrivateDriverData** points to an array of [**D3DKMT_DISPLAYMODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode) structures for the list of display modes.

### `KMTQAITYPE_CHECKDRIVERUPDATESTATUS`

**pPrivateDriverData** points to the driver update status.

### `KMTQAITYPE_VIRTUALADDRESSINFO`

**pPrivateDriverData** points to a [D3DKMT_VIRTUALADDRESSINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_virtualaddressinfo) structure.

Returns information about virtual addressing support.

Supported starting with Windows 7.

### `KMTQAITYPE_DRIVERVERSION`

**pPrivateDriverData** points to a variable that contains a [**D3DKMT_DRIVERVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_qai_driverversion)-typed value that indicates the version of the display driver model that the KMD supports.

Supported starting with Windows 7.

### `KMTQAITYPE_ADAPTERTYPE`

**pPrivateDriverData** points to a [**D3DKMT_ADAPTERTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adaptertype) structure that specifies the graphics adapter type.

Supported starting with Windows 8.

### `KMTQAITYPE_OUTPUTDUPLCONTEXTSCOUNT`

**pPrivateDriverData** points to a [**D3DKMT_OUTPUTDUPLCONTEXTSCOUNT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputduplcontextscount) structure that specifies the number of current [Desktop Duplication API](https://learn.microsoft.com/windows/desktop/direct3ddxgi/desktop-dup-api) (DDA) clients that are attached to a given video present network (VidPN).

Supported starting with Windows 8.

### `KMTQAITYPE_WDDM_1_2_CAPS`

**pPrivateDriverData** points to a [**D3DKMT_WDDM_1_2_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/display/d3dkmt-wddm-1-2-caps) structure that specifies the WDDM 1.2 and later capabilities of the graphics adapter and KMD.

Supported starting with Windows 8.

### `KMTQAITYPE_UMD_DRIVER_VERSION`

**pPrivateDriverData** points to a [**D3DKMT_UMD_DRIVER_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_umd_driver_version) structure that specifies UMD's version.

Supported starting with Windows 8.

### `KMTQAITYPE_DIRECTFLIP_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_DIRECTFLIP_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_directflip_support) structure that specifies whether the UMD supports Direct Flip operations.

Supported starting with Windows 8.

### `KMTQAITYPE_MULTIPLANEOVERLAY_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_MULTIPLANEOVERLAY_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_multiplaneoverlay_support) structure that specifies whether the UMD supports multiplane overlay operations.

Supported starting with Windows 8.1.

### `KMTQAITYPE_DLIST_DRIVER_NAME`

**pPrivateDriverData** points to a [**D3DKMT_DLIST_DRIVER_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dlist_driver_name) structure that specifies the name of the driver that supports the display list (DList) feature.

Supported starting with Windows 8.1.

### `KMTQAITYPE_WDDM_1_3_CAPS`

**pPrivateDriverData** points to a [**D3DKMT_WDDM_1_3_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmt_wddm_1_3_caps) structure with information about supported WDDM 1.3 caps.

Supported starting with Windows 8.1.

### `KMTQAITYPE_MULTIPLANEOVERLAY_HUD_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_MULTIPLANEOVERLAY_HUD_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_multiplaneoverlay_hud_support) structure that specifies whether the UMD supports multiplane overlay heads-up display (HUD) operations.

Supported starting with Windows 8.1.

### `KMTQAITYPE_WDDM_2_0_CAPS`

**pPrivateDriverData** points to a [**D3DKMT_WDDM_2_0_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmt_wddm_2_0_caps) structure with information about supported WDDM 2.0 caps. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_NODEMETADATA`

**pPrivateDriverData** points to a [**D3DKMT_NODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-d3dkmt_nodemetadata) structure that contains metadata about the node. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_CPDRIVERNAME`

**pPrivateDriverData** points to a [**D3DKMT_CPDRIVERNAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_cpdrivername) structure that specifies the name of the driver that supports the content protection (CP) feature. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_XBOX`

**pPrivateDriverData** points to a [**D3DKMT_XBOX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_xbox) structure that specifies information about the Xbox. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_INDEPENDENTFLIP_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_INDEPENDENTFLIP_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_independentflip_support) structure that specifies whether the UMD supports independent flip operations. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_MIRACASTCOMPANIONDRIVERNAME`

**pPrivateDriverData** points to a [**D3DKMT_MIRACASTCOMPANIONDRIVERNAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_miracastcompaniondrivername) structure that specifies the name of the driver that supports the Miracast companion feature. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_PHYSICALADAPTERCOUNT`

**pPrivateDriverData** points to a [**D3DKMT_PHYSICAL_ADAPTER_COUNT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_physical_adapter_count) structure that specifies the number of physical adapters. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_PHYSICALADAPTERDEVICEIDS`

**pPrivateDriverData** points to a [**D3DKMT_QUERY_DEVICE_IDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_query_device_ids) structure that specifies the device ID(s) of the physical adapters. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_DRIVERCAPS_EXT`

**pPrivateDriverData** points to a [**D3DKMT_DRIVERCAPS_EXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-d3dkmt_drivercaps_ext) structure that specifies extended driver capabilities. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_QUERY_MIRACAST_DRIVER_TYPE`

**pPrivateDriverData** points to a [**D3DKMT_MIRACAST_DRIVER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_miracast_driver_type) value that specifies the type of Miracast driver. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_QUERY_GPUMMU_CAPS`

**pPrivateDriverData** points to a [**D3DKMT_QUERY_GPUMMU_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_query_gpummu_caps) structure that specifies GPU memory management unit (MMU) capabilities. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_QUERY_MULTIPLANEOVERLAY_DECODE_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_MULTIPLANEOVERLAY_DECODE_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_multiplaneoverlay_decode_support) structure that specifies whether the UMD supports multiplane overlay decode operations. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_QUERY_HW_PROTECTION_TEARDOWN_COUNT`

**pPrivateDriverData** points to a UNIT value that specifies the hardware protection teardown count. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_QUERY_ISBADDRIVERFORHWPROTECTIONDISABLED`

**pPrivateDriverData** points to a [**D3DKMT_ISBADDRIVERFORHWPROTECTIONDISABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_isbaddriverforhwprotectiondisabled) structure that specifies whether a bad driver for hardware protection is disabled. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_MULTIPLANEOVERLAY_SECONDARY_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_MULTIPLANEOVERLAY_SECONDARY_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_multiplaneoverlay_secondary_support) structure that specifies whether the UMD provides multiplane overlay support for secondary displays. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_INDEPENDENTFLIP_SECONDARY_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_INDEPENDENTFLIP_SECONDARY_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_independentflip_secondary_support) structure that specifies whether the UMD supports independent flip operations for secondary displays. Supported starting with Windows 10 (WDDM 2.0).

### `KMTQAITYPE_PANELFITTER_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_PANELFITTER_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_panelfitter_support) structure that specifies whether the UMD supports panel fitter operations. Supported starting with Windows 10, version 1607 (WDDM 2.1).

### `KMTQAITYPE_PHYSICALADAPTERPNPKEY`

**pPrivateDriverData** points to a [**D3DKMT_QUERY_PHYSICAL_ADAPTER_PNPKEY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_query_physical_adapter_pnp_key) structure that specifies the physical adapter's plug-and-play (PNP) key. Supported starting with Windows 10, version 1703 (WDDM 2.2).

### `KMTQAITYPE_GETSEGMENTGROUPSIZE`

**pPrivateDriverData** points to a [**D3DKMT_SEGMENTGROUPSIZEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_segmentgroupsizeinfo) structure that specifies the information about the segment group size. Supported starting with Windows 10, version 1703 (WDDM 2.2).

### `KMTQAITYPE_MPO3DDI_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_MPO3DDI_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_mpo3ddi_support) structure that specifies whether the driver supports the [multiplane overlay version 3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3) operations. Available starting with Windows 10, version 1703 (WDDM 2.2).

### `KMTQAITYPE_HWDRM_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_HWDRM_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_hwdrm_support) structure that specifies whether the driver supports hardware digital rights management (DRM) operations. Available starting with Windows 10, version 1703 (WDDM 2.2).

### `KMTQAITYPE_MPOKERNELCAPS_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_MPOKERNELCAPS_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_mpokernelcaps_support) structure that specifies whether multiplane overlay kernel capabilities are supported. Available starting with Windows 10, version 1703 (WDDM 2.2).

### `KMTQAITYPE_MULTIPLANEOVERLAY_STRETCH_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_MULTIPLANEOVERLAY_STRETCH_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_multiplaneoverlay_stretch_support) structure that specifies whether the driver supports multiplane overlay stretch operations. Available starting with Windows 10, version 1703 (WDDM 2.2).

### `KMTQAITYPE_GET_DEVICE_VIDPN_OWNERSHIP_INFO`

**pPrivateDriverData** points to a [**D3DKMT_GET_DEVICE_VIDPN_OWNERSHIP_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_get_device_vidpn_ownership_info) structure that specifies the ownership state of the video present network (VidPN) for a given device. Available starting with Windows 10, version 1703 (WDDM 2.2).

### `KMTQAITYPE_QUERYREGISTRY`

**pPrivateDriverData** points to a [**D3DKMT_ADAPTERREGISTRYINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapterregistryinfo) structure, where the last field is actually variable-sized by the caller.

This type queries the registry for information that is commonly cached during driver installation.
User-mode components must use this technique to support paravirtualized adapters, instead of relying on native OS methods. For more information, see [GPU virtualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization).

Support for this type started with Windows 10, version 1803 WDDM 2.4.

### `KMTQAITYPE_KMD_DRIVER_VERSION`

### `KMTQAITYPE_BLOCKLIST_KERNEL`

### `KMTQAITYPE_BLOCKLIST_RUNTIME`

### `KMTQAITYPE_ADAPTERGUID_RENDER`

### `KMTQAITYPE_ADAPTERADDRESS_RENDER`

### `KMTQAITYPE_ADAPTERREGISTRYINFO_RENDER`

### `KMTQAITYPE_CHECKDRIVERUPDATESTATUS_RENDER`

### `KMTQAITYPE_DRIVERVERSION_RENDER`

### `KMTQAITYPE_ADAPTERTYPE_RENDER`

### `KMTQAITYPE_WDDM_1_2_CAPS_RENDER`

### `KMTQAITYPE_WDDM_1_3_CAPS_RENDER`

### `KMTQAITYPE_QUERY_ADAPTER_UNIQUE_GUID`

### `KMTQAITYPE_NODEPERFDATA`

### `KMTQAITYPE_ADAPTERPERFDATA`

### `KMTQAITYPE_ADAPTERPERFDATA_CAPS`

### `KMTQUITYPE_GPUVERSION`

### `KMTQAITYPE_DRIVER_DESCRIPTION`

### `KMTQAITYPE_DRIVER_DESCRIPTION_RENDER`

### `KMTQAITYPE_SCANOUT_CAPS`

### `KMTQAITYPE_DISPLAY_UMDRIVERNAME`

### `KMTQAITYPE_PARAVIRTUALIZATION_RENDER`

### `KMTQAITYPE_SERVICENAME`

### `KMTQAITYPE_WDDM_2_7_CAPS`

### `KMTQAITYPE_TRACKEDWORKLOAD_SUPPORT`

### `KMTQAITYPE_HYBRID_DLIST_DLL_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_HYBRID_DLIST_DLL_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_hybrid_dlist_dll_support) structure. Supported starting with Windows 10, version 2004 (WDDM 2.7).

### `KMTQAITYPE_DISPLAY_CAPS`

### `KMTQAITYPE_WDDM_2_9_CAPS`

**pPrivateDriverData** points to a [**D3DKMT_WDDM_2_9_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-d3dkmt_wddm_2_9_caps) structure with information about supported WDDM 2.9 caps. Supported starting with Windows Server 2022.

### `KMTQAITYPE_CROSSADAPTERRESOURCE_SUPPORT`

**pPrivateDriverData** points to a [**D3DKMT_CROSSADAPTERRESOURCE_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_crossadapterresource_support) structure. Supported starting with Windows Server 2022.

### `KMTQAITYPE_WDDM_3_0_CAPS`

**pPrivateDriverData** points to a [**D3DKMT_WDDM_3_0_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-d3dkmt_wddm_3_0_caps) structure with information about supported WDDM 3.0 caps. Supported starting with Windows 11, version 21H2.

### `KMTQAITYPE_WSAUMDIMAGENAME`

### `KMTQAITYPE_VGPUINTERFACEID`

### `KMTQAITYPE_WDDM_3_1_CAPS`

**pPrivateDriverData** points to a [**D3DKMT_WDDM_3_1_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-d3dkmt_wddm_3_1_caps) structure with information about supported WDDM 3.1 caps. Supported starting with Windows 11, version 22H2.

## Remarks

Each enum value denotes how to interpret the other fields of **D3DKMT_QUERYADAPTERINFO**, especially **D3DKMT_QUERYADAPTERINFO::pPrivateDriverData**.
**pPrivateDriverData** is commonly reinterpreted as a unique structure, corresponding to each enum value. Exceptions do exist, as detailed above.

## See also

[**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[**PFND3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_queryadapterinfo)