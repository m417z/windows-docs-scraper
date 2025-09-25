# ADS_BACKLINK structure

## Description

The **ADS_BACKLINK** structure is an ADSI representation of the **Back Link** attribute syntax.

## Members

### `RemoteID`

Identifier of the remote server that requires an external reference to the object specified by **ObjectName**. See below.

### `ObjectName`

The null-terminated Unicode string that specifies the name of an object to which the **Back Link** attribute is attached.

## Remarks

A **Back Link** attribute contains one or more servers that hold an external reference to the attached object.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)