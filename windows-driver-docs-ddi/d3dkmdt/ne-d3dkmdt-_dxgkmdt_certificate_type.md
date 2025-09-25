# DXGKMDT_CERTIFICATE_TYPE enumeration

## Description

The **DXGKMDT_CERTIFICATE_TYPE** enumeration identifies the type of certificate that callers of the [**DxgkDdiOPMGetCertificateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_certificate_size) and [**DxgkDdiOPMGetCertificate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_certificate) functions require.

## Constants

### `DXGKMDT_OPM_CERTIFICATE`

Indicates an Output Protection Management (OPM) certificate.

### `DXGKMDT_COPP_CERTIFICATE`

Indicates a Certified Output Protection Protocol (COPP) certificate.

### `DXGKMDT_UAB_CERTIFICATE`

Indicates a User Accessible Bus (UAB) certificate.

### `DXGKMDT_INDIRECT_DISPLAY_CERTIFICATE`

### `DXGKMDT_FORCE_ULONG`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## Remarks

For more information about certificates that are used with OPM, download the [Output Content Protection and Windows Vista](https://view.officeapps.live.com/op/view.aspx?src=https%3A%2F%2Fdownload.microsoft.com%2Fdownload%2F5%2FD%2F6%2F5D6EAF2B-7DDF-476B-93DC-7CF0072878E6%2Foutput_protect.doc%3Fwww.dailytech.com&wdOrigin=BROWSELINK) document.

## See also

[**DxgkDdiOPMGetCertificate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_certificate)

[**DxgkDdiOPMGetCertificateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_certificate_size)