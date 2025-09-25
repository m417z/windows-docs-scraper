# TF_DA_ATTR_INFO enumeration

## Description

Elements of the **TF_DA_ATTR_INFO** enumeration are used to specify text conversion data in the [TF_DISPLAYATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_displayattribute) structure.

## Constants

### `TF_ATTR_INPUT:0`

The text is entered by the user and has not been converted yet.

### `TF_ATTR_TARGET_CONVERTED:1`

The user has made a character selection and the text has been converted yet.

### `TF_ATTR_CONVERTED:2`

The text is converted.

### `TF_ATTR_TARGET_NOTCONVERTED:3`

The user made a character selection, but the text is not converted yet.

### `TF_ATTR_INPUT_ERROR:4`

The text is an error character and cannot be converted. For example, some consonants cannot be put together.

### `TF_ATTR_FIXEDCONVERTED:5`

The text is not converted. Theses characters will no longer be converted.

### `TF_ATTR_OTHER:-1`

Reserved for the system.

## See also

[TF_DISPLAYATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_displayattribute)