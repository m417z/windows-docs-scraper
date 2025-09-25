# DXGKDDI_OPM_GET_CERTIFICATE_SIZE callback function

## Description

The **DxgkDdiOPMGetCertificateSize** function retrieves the size of a certificate of the given type.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block that is associated with a display adapter. Previously, the display miniport driver's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function provided this handle to the DirectX graphics kernel subsystem.

### `CertificateType` [in]

A [**DXGKMDT_CERTIFICATE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_certificate_type)-typed value that identifies the type of certificate whose size **DxgkDdiOPMGetCertificateSize** returns.

### `CertificateSize` [out]

A pointer to a variable that receives the size, in bytes, of the certificate whose type is identified by the value in the **CertificateType** parameter.

## Return value

**DxgkDdiOPMGetCertificateSize** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The function successfully retrieved the certificate size.|
| STATUS_GRAPHICS_OPM_NOT_SUPPORTED | The display miniport driver does not support OPM either because the hardware vendor never signed the OPM license agreement or the miniport driver's graphics hardware does not comply with OPM rules. DxgkDdiOPMGetCertificateSize can also return this value if the display miniport driver detected tampering.|
| STATUS_GRAPHICS_COPP_NOT_SUPPORTED | The display miniport driver does not support COPP either because the hardware vendor never signed the COPP license agreement or the miniport driver's graphics hardware does not comply with COPP rules. DxgkDdiOPMGetCertificateSize can also return this value if the miniport driver detected tampering.|
| STATUS_GRAPHICS_UAB_NOT_SUPPORTED | The display miniport driver does not support UAB either because the hardware vendor never signed the UAB license agreement or the miniport driver's graphics hardware does not comply with UAB rules. DxgkDdiOPMGetCertificateSize can also return this value if the display miniport driver detected tampering.|
| STATUS_GRAPHICS_PVP_HFS_FAILED | The display miniport driver's hardware functionality scan (HFS) failed or the display miniport driver detected tampering. A display miniport driver can optionally return this value. If DxgkDdiOPMGetCertificateSize does not return this value for tampering, it can return one of the previous error codes instead.|

This function might also return other error codes that are defined in *Ntstatus.h*.

## Remarks

**DxgkDdiOPMGetCertificateSize** can retrieve the size of the display miniport driver's OPM certificate, User Accessible Bus (UAB) certificate, or Certified Output Protection Protocol (COPP) certificate. For information about these certificates, download the [Output Content Protection and Windows Vista](https://view.officeapps.live.com/op/view.aspx?src=https%3A%2F%2Fdownload.microsoft.com%2Fdownload%2F5%2FD%2F6%2F5D6EAF2B-7DDF-476B-93DC-7CF0072878E6%2Foutput_protect.doc%3Fwww.dailytech.com&wdOrigin=BROWSELINK) document.

**DxgkDdiOPMGetCertificateSize** should be made pageable.

## See also

[**DXGKMDT_CERTIFICATE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_certificate_type)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)