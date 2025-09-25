# ICertProperty::get_PropertyId

## Description

The **PropertyId** property specifies or retrieves a value of the [CERTENROLL_PROPERTYID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_propertyid) enumeration that identifies an external certificate property.

This property is read/write.

## Parameters

## Remarks

 Call the **PropertyId** property before trying to initialize the [ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty) object. Call the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-initializedecode) method or the [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-initializefromcertificate) method to create a value for the certificate property. Call the [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-get_rawdata) property to retrieve the property value.

## See also

[ICertProperties](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperties)

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)