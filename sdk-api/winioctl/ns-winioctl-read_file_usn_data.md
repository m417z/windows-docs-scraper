# READ_FILE_USN_DATA structure

## Description

Specifies the versions of the update sequence number (USN) change journal supported by the
application. This structure is the input structure to the
[FSCTL_READ_FILE_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_read_file_usn_data) control code.

## Members

### `MinMajorVersion`

The lowest version of the USN change journal accepted by the application. If the input buffer is not
specified this defaults to 2.

### `MaxMajorVersion`

The highest version of the USN change journal accepted by the application. If the input buffer is not
specified this defaults to 2. To support 128-bit file identifiers used by ReFS this must be 3 or higher.

## See also

[FSCTL_READ_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_read_usn_journal)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)