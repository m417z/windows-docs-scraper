# STREAM_INFO_LEVELS enumeration

## Description

Defines values that are used with the
[FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw) function to specify the information
level of the returned data.

## Constants

### `FindStreamInfoStandard`

The [FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw) function retrieves standard
stream information. The data is returned in a
[WIN32_FIND_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_find_stream_data) structure.

### `FindStreamInfoMaxInfoLevel`

Used to determine valid enumeration values. All supported enumeration values are less than
**FindStreamInfoMaxInfoLevel**.

## See also

[FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw)

[WIN32_FIND_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_find_stream_data)