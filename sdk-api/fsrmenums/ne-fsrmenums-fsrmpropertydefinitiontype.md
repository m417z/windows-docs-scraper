# FsrmPropertyDefinitionType enumeration

## Description

Defines the types of file classification properties that you can define.

## Constants

### `FsrmPropertyDefinitionType_Unknown:0`

The type is unknown. Do not use this value.

### `FsrmPropertyDefinitionType_OrderedList:1`

A classification property that defines an ordered list of possible string values, one of which may be
assigned to the property.

The aggregation policy for this type is to use the order in which the items are added to the list to
determine which value to use if the property exists and contains a value that is different from the rule's
value. For example, if the list contains "HBI", "MBI", and
"LBI", and one source specifies "MBI" and the other source specifies
"HBI", the property value is set to "HBI" because it appears before
"MBI" in the list.

You can use the following comparison operators with this type (see
[FsrmPropertyConditionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertyconditiontype)): Equal, Not equal,
Greater than, Less than, Exists, and Not exists.

### `FsrmPropertyDefinitionType_MultiChoiceList:2`

A classification property that defines a list of possible string values, one or more of which may be assigned
to the property. Use the vertical bar character (|) to delimit the strings.

The aggregation policy for this type is to concatenate the values from each source, consolidating any
duplicates. For example, if the list of possible values contains "Cat1",
"Cat2", "Cat3", and "Cat4", and one source specifies
"Cat3" and another source specifies "Cat1", the property value is set to
"Cat1|Cat3".

You can use the following comparison operators with this type (see
[FsrmPropertyConditionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertyconditiontype)): Equal, Not equal,
Contains, Contained in, Exists, and Not exists.

### `FsrmPropertyDefinitionType_SingleChoiceList:3`

A classification property that defines a list of possible string values, only one of which may be assigned
to the property.

No aggregation is available for this type.

You can use the following comparison operators with this type (see
[FsrmPropertyConditionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertyconditiontype)): Equal, Not equal,
Exists, and Not exists.

**Windows Server 2008 R2 and Windows Server 2008:** This file classification property type is not supported before Windows Server 2012.

### `FsrmPropertyDefinitionType_String:4`

A classification property that contains an arbitrary string value.

The aggregation policy is to fail if two sources do not specify the same value.

You can use the following comparison operators with this type (see
[FsrmPropertyConditionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertyconditiontype)): Equal, Not equal,
Greater than, Less than, Contains, Contained in, Start with, End with, Prefix of, Suffix of, Exists, and Not
exists.

### `FsrmPropertyDefinitionType_MultiString:5`

A classification property that contains one or more arbitrary string values. Use the vertical bar character
(|) to delimit the strings.

The aggregation policy is to concatenate the values from each source, consolidating any duplicates. For
example if one source specifies "String1|String2" and another source specifies
"String1|String3", the property value is set to "String1|String2|String3".

You can use the following comparison operators with this type (see
[FsrmPropertyConditionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertyconditiontype)): Equal, Not equal,
Contains, Contained in, Exists, and Not exists.

### `FsrmPropertyDefinitionType_Int:6`

A classification property that contains a decimal integer value expressed as a string.

The aggregation policy is to fail if two sources do not specify the same value.

You can use the following comparison operators with this type (see
[FsrmPropertyConditionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertyconditiontype)): Equal, Not equal,
Greater than, Less than, Exists, and Not exists.

### `FsrmPropertyDefinitionType_Bool:7`

A classification property that contains a Boolean value expressed as a string. Use a string value of
"0" for **False** or a string value of "1" for
**True**.

The aggregation policy is to perform a logical **OR** on the values from each
source. For example, if one source specifies **True** and another source specifies
**False**, the property value is set to **True**. If two sources
both specify **False**, the property value is set to **False**.

You can use the following comparison operators with this type (see
[FsrmPropertyConditionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertyconditiontype)): Equal, Not equal,
Exists, and Not exists.

### `FsrmPropertyDefinitionType_Date:8`

A classification property that contains a date value. The date value is a 64-bit decimal number (see
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)) expressed as a string.

The aggregation policy is to fail if two sources do not specify the same value.

You can use the following comparison operators with this type (see
[FsrmPropertyConditionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertyconditiontype)): Equal, Not equal,
Greater than, Less than, Exists, and Not exists.

## See also

[IFsrmPropertyDefinition.Type](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertydefinition-get_type)