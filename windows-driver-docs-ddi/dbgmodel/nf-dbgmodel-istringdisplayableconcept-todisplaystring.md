# IStringDisplayableConcept::ToDisplayString

## Description

The ToDisplayString method is called whenever a client wishes to convert an object into a string to display (to console, in the UI, etc...). Such a string conversion should not be used for the basis of additional programmatic manipulation. The string conversion itself may be deeply influenced by the metadata passed to the call. A string conversion should make every attempt to honor the PreferredRadix and PreferredFormat keys.

## Parameters

### `contextObject`

The instance (this pointer) being converted to a display string is passed in this argument.

### `metadata`

An optional metadata store which defines how the caller would like the string to be converted. The implementation should make every attempt to honor the requests in the store (in particular, the PreferredRadix and PreferredFormat keys).

### `displayString`

The string conversion as allocated by the SysAllocString function will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IStringDisplayableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-istringdisplayableconcept)