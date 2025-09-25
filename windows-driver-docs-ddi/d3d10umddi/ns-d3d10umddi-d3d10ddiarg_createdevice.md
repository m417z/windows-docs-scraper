# D3D10DDIARG_CREATEDEVICE structure

## Description

The **D3D10DDIARG_CREATEDEVICE** structure describes the display device to create.

## Members

### `hRTDevice`

[in] A handle to the display device (graphics context) that specifies the handle that the driver should use when it calls back into the Direct3D runtime (that is, when the driver calls functions that the **pKTCallbacks** member specifies).

### `Interface`

[in] The Direct3D interface version. The high 16 bits store the major release number (such as 10, 11, and so on); the low 16 bits store the minor release number (such as 0, 1, 2, and so on). The minor release number will be increased when a change to the interface is released.

### `Version`

[in] A number that the driver can use to identify when the Direct3D runtime was built. The high 16 bits represent the build number; the low 16 bits represent the revision number.

The driver is required only to monitor the high 16 bits. The driver should ensure that the runtime build version that is passed in is greater than or equal to the current build version of the driver. The driver should return a failure from its [**CreateDevice(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function if the passed in build version is incompatible.

### `pKTCallbacks`

[in] A pointer to a [**D3DDDI_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks) structure that contains a table of Direct3D runtime callback functions that the driver can use to access kernel services.

### `pDeviceFuncs`

[in/out] A pointer to a [**D3D10DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. The Direct3D runtime uses these functions to communicate with the user-mode display driver.

The driver should fill its Direct3D version 10.0 functions in the supplied [**D3D10DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs) structure when the value in the **Interface** member is **D3D10_0_DDI_INTERFACE_VERSION**.

### `p10_1DeviceFuncs`

[in/out] A pointer to a [**D3D10_1DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. Version 10.1 of the Direct3D runtime uses these functions to communicate with the user-mode display driver.

The driver should fill its Direct3D version 10.1 functions in the supplied [**D3D10_1DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs) structure when the value in the **Interface** member is **D3D10_1_DDI_INTERFACE_VERSION**.

Supported starting with Windows Vista with SP1 and Windows Server 2008.

### `p11DeviceFuncs`

[in/out] A pointer to a [**D3D11DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. Version 11 of the Direct3D runtime uses these functions to communicate with the user-mode display driver.

The driver should fill its Direct3D version 11.0 functions in the supplied [**D3D11DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs) structure when the value in the **Interface** member is **D3D11_0_DDI_INTERFACE_VERSION**.

Supported starting with Windows 7.

### `p11_1DeviceFuncs`

[in/out] A pointer to a [**D3D11_1DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. Starting with version 11.1, the Direct3D runtime uses these functions to communicate with the user-mode display driver.

The driver should fill its Direct3D version 11.1 functions in the supplied [**D3D11_1DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_devicefuncs) structure when the value in the **Interface** member is **D3D11_1_DDI_INTERFACE_VERSION**.

Supported starting with Windows 8.

### `pWDDM1_3DeviceFuncs`

[in/out] A pointer to a [**D3DWDDM1_3DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. Version 11.2 of the Direct3D runtime uses these functions to communicate with the user-mode display driver.

The driver should fill its Direct3D version 11.2 functions in the supplied [**D3DWDDM1_3DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_devicefuncs) structure when the value in the **Interface** member is **D3DWDDM1_3_DDI_INTERFACE_VERSION**.

Supported starting with Windows 8.1.

### `pWDDM2_0DeviceFuncs`

[in/out] A pointer to a [**D3DWDDM2_0DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. The driver should fill its Direct3D functions in the supplied structure when the value in the **Interface** member is **D3DWDDM2_0_DDI_INTERFACE_VERSION**.

### `pWDDM2_1DeviceFuncs`

[in/out] A pointer to a [**D3DWDDM2_1DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_1ddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. The driver should fill its Direct3D functions in the supplied structure when the value in the **Interface** member is **D3DWDDM2_0_DDI_INTERFACE_VERSION**.

### `pWDDM2_2DeviceFuncs`

[in/out] A pointer to a [**D3DWDDM2_2DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_2ddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. The driver should fill its Direct3D functions in the supplied structure when the value in the **Interface** member is **D3DWDDM2_0_DDI_INTERFACE_VERSION**.

### `pWDDM2_6DeviceFuncs`

[in/out] A pointer to a [**D3DWDDM2_6DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_6ddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. The driver should fill its Direct3D functions in the supplied structure when the value in the **Interface** member is **D3DWDDM2_0_DDI_INTERFACE_VERSION**.

Supported starting with Windows 10, version 1901.

### `hDrvDevice`

[in/out] A handle to the display device (graphics context) that the Direct3D runtime uses in subsequent driver calls to identify the display device.

### `DXGIBaseDDI`

[in/out] A [**DXGI_DDI_BASE_ARGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_args) structure that provides access to the DXGI. The DXGI DDI handles low-level tasks like presenting rendered frames to an output, controlling gamma, and managing a full-screen transition.

### `hRTCoreLayer`

[in] A handle that the driver should use when it calls back into the Direct3D runtime to access core Direct3D 10 functionality (that is, when the driver calls functions that the **pUMCallbacks** member specifies).

### `pUMCallbacks`

[in] A pointer to a [**D3D10DDI_CORELAYER_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_corelayer_devicecallbacks) structure that contains a table of Direct3D 10 runtime callback functions that the driver can use to access core user-mode runtime functionality.

### `p11UMCallbacks`

[in] A pointer to a [**D3D11DDI_CORELAYER_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_corelayer_devicecallbacks) structure that contains a table of Direct3D 10 and Direct3D 11 runtime callback functions, which the driver can use to access core user-mode runtime functionality.

Supported starting with Windows 7.

### `pWDDM2_0UMCallbacks`

[in] Pointer to a [**D3DWDDM2_0DDI_CORELAYER_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_corelayer_devicecallbacks) structure that contains a table of Direct3D 10, Direct3D 11, and WDDM 2.0 runtime callback functions, which the driver can use to access core user-mode runtime functionality.

### `pWDDM2_2UMCallbacks`

[in] Pointer to a [**D3DWDDM2_2DDI_CORELAYER_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_2ddi_corelayer_devicecallbacks) structure that contains a table of Direct3D 10, Direct3D 11, WDDM 2.0, and WDDM 2.2 runtime callback functions, which the driver can use to access core user-mode runtime functionality.

### `pWDDM2_6UMCallbacks`

[in] Pointer to a [**D3DWDDM2_6DDI_CORELAYER_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_6ddi_corelayer_devicecallbacks) structure that contains a table of Direct3D 10, Direct3D 11, WDDM 2.0, WDDM 2.2, and WDDM 2.6 runtime callback functions, which the driver can use to access core user-mode runtime functionality.

### `Flags`

[in] A valid bitwise OR of flag values that identify how to create the display device. The Direct3D runtime supports the following flags:

| Flag | Meaning |
| ---- | ------- |
| D3D10DDI_CREATEDEVICE_FLAG_DISABLE_EXTRA_THREAD_CREATION (0x1) | If this flag is set, the user-mode display driver should not run multiple threads simultaneously when it processes calls to its functions from the Direct3D runtime. A driver can typically start and run multiple threads to process operations faster, unless the **D3D10DDI_CREATEDEVICE_FLAG_DISABLE_EXTRA_THREAD_CREATION** flag is set. |
| D3D11DDI_CREATEDEVICE_FLAG_SINGLETHREADED (0x10) | Informs the user-mode display driver that the application is single threaded. The Direct3D 11 runtime allows multiple application threads to enter the driver if the driver allows this mode of operation. However, not all applications can run multiple threads. If this flag is set, the driver does not expect multiple threads to enter it and run simultaneously. The driver can avoid synchronization if this flag is set. Supported starting with Windows 7. |
| The flag that is set in the 0xE mask of the **Flags** member | Represents the level of 3-D pipeline that the driver should support for the display device. See Remarks. Supported starting with Windows 7. |

### `ppfnRetrieveSubObject`

[in/out] A pointer to a [**RetrieveSubObject(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_retrievesubobject) function that retrieves subparts of a Direct3D driver device object.

Supported starting with Windows 8.

## Remarks

The driver examines values in the **Interface** and **Version** members to determine whether to fill the [**D3D10DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs), [**D3D10_1DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs), [**D3D11DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs), [**D3D11_1DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_devicefuncs), or [**D3DWDDM1_3DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_devicefuncs) structure that the **pDeviceFuncs**, **p10_1DeviceFuncs**, **p11DeviceFuncs**, **p11_1DeviceFuncs**, or **pWDDM1_3DeviceFuncs** member points to with the driver's functions. The following constants from D3d10umddi.h are examples of the constants that the driver might find in **Interface** and **Version**:

```cpp
#define D3D10_1_DDI_MINOR_VERSION 2
#define D3D10_1_DDI_INTERFACE_VERSION ((D3D10_DDI_MAJOR_VERSION << 16) | D3D10_1_DDI_MINOR_VERSION)
#define D3D10_1_DDI_BUILD_VERSION 1
#define D3D10_1_DDI_SUPPORTED ((((UINT64)D3D10_1_DDI_INTERFACE_VERSION) << 32) | (((UINT64)D3D10_1_DDI_BUILD_VERSION) << 16))
```

Other possible combinations of constants for different versions of the operating system, Direct3D, and Windows Display Driver Model (WDDM) are listed in the *D3d10umddi.h* header.

 For the flag that is set in the 0xE mask of the **Flags** member, the driver uses the following constant and macros to extract one of the values from the [**D3D11DDI_3DPIPELINELEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_3dpipelinelevel) enumeration that represent the 3-D pipeline level to support. The value in the **Flags** member is formatted like the **Caps** member of the [**D3D11DDI_3DPIPELINESUPPORT_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_3dpipelinesupport_caps) structure.

```cpp
#define D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_SHIFT (0x1)
#define D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_MASK (0x7 << D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_SHIFT)
#define D3D11DDI_EXTRACT_3DPIPELINELEVEL_FROM_FLAGS( Flags ) \
    ((D3D11DDI_3DPIPELINELEVEL)(((Flags) & D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_MASK) >> \
    D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_SHIFT))
```

## See also

[**CreateDevice(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[**D3D10DDI_CORELAYER_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_corelayer_devicecallbacks)

[**D3D10DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[**D3D10_1DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs)

[**D3D11DDI_3DPIPELINELEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_3dpipelinelevel)

[**D3D11DDI_3DPIPELINESUPPORT_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_3dpipelinesupport_caps)

[**D3D11DDI_CORELAYER_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_corelayer_devicecallbacks)

[**D3D11DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[**D3D11_1DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_devicefuncs)

[**D3DDDI_ALLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist)

[**D3DDDI_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[**D3DDDI_PATCHLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist)

[**D3DWDDM1_3DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_devicefuncs)

[**DXGI_DDI_BASE_ARGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_args)

[**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)

[**RetrieveSubObject(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_retrievesubobject)