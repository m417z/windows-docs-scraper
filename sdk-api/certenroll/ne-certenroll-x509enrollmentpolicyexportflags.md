# X509EnrollmentPolicyExportFlags enumeration

## Description

The **X509EnrollmentPolicyExportFlags** enumeration is used by the [Export](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-export) method on the [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) interface to specify what items to export from the policy server.

## Constants

### `ExportTemplates:0x1`

Export templates.

### `ExportOIDs:0x2`

Export custom object identifiers.

### `ExportCAs:0x4`

Not used.

## Remarks

To export both templates and object identifiers, specify a bitwise **OR** of the **ExportTemplates** and **ExportOIDs** values.

## See also

[Export](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-export)