# IOCSPCAConfiguration::put_ReminderDuration

## Description

The **ReminderDuration** property gets or sets the percentage of a signing certificate lifetime after which a warning event is logged.

This property is read/write.

## Parameters

## Remarks

Percentage values must be in the range 0 through 100; the default value is 90. An Online Certificate Status Protocol (OCSP) responder service includes a service-wide value having this default.

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)