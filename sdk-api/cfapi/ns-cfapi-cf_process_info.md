# CF_PROCESS_INFO structure

## Description

Contains information about a user process that triggers a callback.

## Members

### `StructSize`

The size of the **CF_PROCESS_INFO** structure.

### `ProcessId`

The 32 bit ID of the user process.

### `ImagePath`

The absolute path of the main executable file including the volume name in the format of NT file path. If the platform failed to retrieve the image path, `UNKNOWN` will be returned.

### `PackageName`

Used for modern applications. The app package name.

### `ApplicationId`

Used for modern applications. The application ID.

### `CommandLine`

>[!NOTE]
>This member was added in Windows 10, version 1803.

The string that is used to start the process. If the platform failed to retrieve the command line, `UNKNOWN` will be returned.

### `SessionId`

>[!NOTE]
>This member was added in Windows 10, version 1803.

The 32bit ID of the session wherein the user process that triggers the callback resides.

## See also

[CF_CALLBACK_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_callback_info)