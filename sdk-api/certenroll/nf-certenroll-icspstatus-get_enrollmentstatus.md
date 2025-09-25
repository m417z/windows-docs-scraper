# ICspStatus::get_EnrollmentStatus

## Description

The **EnrollmentStatus** property retrieves an [IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus) object that contains information about the certificate enrollment.

This property is read-only.

## Parameters

## Remarks

This property returns an [IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus) object. This object is typically populated when you create a PKCS #10 certificate request. The following three properties returned by this object provide information about the provider/algorithm pair represented by an [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object:

* The [Display](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_display) property specifies whether the provider and algorithm should be displayed in a user interface.
* The [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property specifies whether the provider and algorithm can be used to create a key pair for a certificate request.
* The [Status](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_status) property specifies whether the provider and algorithm were skipped or resulted in an error during request initialization.

To understand how these properties are important, assume that a certificate request is based on a template that specifies a particular provider and algorithm. The [Display](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_display) and [Status](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_status) properties for this provider/algorithm pair are enabled. For other [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects, one or both of these properties may not be enabled. For more complete examples, see the [Ordinal](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatus-get_ordinal) property.

The [Status](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_status) property is set to **EnrollUnknown** when the [IX509EnrollmentStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentstatus) object is first created. If a provider/algorithm pair is not selected, the status may be set to **EnrollSkipped**. The status will be set to **EnrollError** if key creation fails for the selected provider and algorithm during certificate initialization.

## See also

[ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus)

[ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses)