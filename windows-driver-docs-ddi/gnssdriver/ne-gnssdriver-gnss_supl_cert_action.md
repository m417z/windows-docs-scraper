# GNSS_SUPL_CERT_ACTION enumeration

## Description

This enumeration indicates the action to take upon receipt of the SUPL certificate, which is defined by the [GNSS_SUPL_CERT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_supl_cert_config) structure.

## Constants

### `GNSS_Supl_Cert_Inject`

Indicates that the certificate should be injected.

### `GNSS_Supl_Cert_Delete`

Indicates that the certificate specified by the **SuplCertName** member of the [GNSS_SUPL_CERT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_supl_cert_config) structure should be deleted.

### `GNSS_Supl_Cert_Purge`

Indicates that all certificates previously injected into the GNSS driver should be deleted.