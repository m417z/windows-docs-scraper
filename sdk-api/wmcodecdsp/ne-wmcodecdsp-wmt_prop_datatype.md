# WMT_PROP_DATATYPE enumeration

## Description

Defines the data types used for the codec and DSP properties that are accessed by using the methods of the [IWMCodecProps](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecprops) interface.

## Constants

### `WMT_PROP_TYPE_DWORD:0`

Specifies a double-word value.

### `WMT_PROP_TYPE_STRING:1`

Specifies a string value.

### `WMT_PROP_TYPE_BINARY:2`

Specifies a binary value.

### `WMT_PROP_TYPE_BOOL:3`

Specifies a Boolean value.

### `WMT_PROP_TYPE_QWORD:4`

Specifies a quadruple-word value.

### `WMT_PROP_TYPE_WORD:5`

Specifies a word value.

### `WMT_PROP_TYPE_GUID:6`

Specifies a GUID value.

## Remarks

Most properties are accessed by using the methods of the **IPropertyBag** interface. The data types of those properties are defined as constants used with **VARIANTARG** values.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)