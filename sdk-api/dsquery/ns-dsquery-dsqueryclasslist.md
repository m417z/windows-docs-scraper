# DSQUERYCLASSLIST structure

## Description

The **DSQUERYCLASSLIST** structure describes a list of classes against which a directory service query is made.

## Members

### `cbStruct`

Size, in bytes, of this structure.

### `cClasses`

Number of the classes in the array.

### `offsetClass`

Offset to the class names of Unicode strings.

## Remarks

The class list is retrieved by the form pages upon receiving a DSQPM_GETCLASSLIST page message.

## See also

[Active
Directory Display Structures](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)