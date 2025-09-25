# FsrmPropertyConditionType enumeration

## Description

Defines the possible comparison operations that can be used to determine whether a property value of a
file meets a particular condition.

## Constants

### `FsrmPropertyConditionType_Unknown:0`

The operator is unknown; do not use this value.

### `FsrmPropertyConditionType_Equal:1`

The property condition is met if the property value is equal to a specified value.

### `FsrmPropertyConditionType_NotEqual:2`

The property condition is met if the property value is not equal to a specified value.

### `FsrmPropertyConditionType_GreaterThan:3`

The property condition is met if the property value is greater than a specified value.

### `FsrmPropertyConditionType_LessThan:4`

The property condition is met if the property value is less than a specified value.

### `FsrmPropertyConditionType_Contain:5`

The property condition is met if the property value contains the specified value.

### `FsrmPropertyConditionType_Exist:6`

The property condition is met if the property value exists.

### `FsrmPropertyConditionType_NotExist:7`

The property condition is met if the property value does not exist.

### `FsrmPropertyConditionType_StartWith:8`

The property condition is met if the property value starts with the specified value.

### `FsrmPropertyConditionType_EndWith:9`

The property condition is met if the property value ends with the specified value.

### `FsrmPropertyConditionType_ContainedIn:10`

The property condition is met if the property value is contained in the specified value.

### `FsrmPropertyConditionType_PrefixOf:11`

The property condition is met if the property value is a prefix of the specified value.

### `FsrmPropertyConditionType_SuffixOf:12`

The property condition is met if the property value is a suffix of the specified value.

### `FsrmPropertyConditionType_MatchesPattern:13`

The property condition is met if the property value matches the specified pattern. The pattern format is a
semicolon-separated list of wildcard patterns. For example "*.exe;*.com"

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[IFsrmFileConditionProperty.Operator](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfileconditionproperty-get_operator)

[IFsrmPropertyCondition.Type](https://learn.microsoft.com/windows/win32/api/fsrmreports/nf-fsrmreports-ifsrmpropertycondition-get_type)