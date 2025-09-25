# PSP_FILE_CALLBACK_A callback function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
*FileCallback* callback function is used by a few setup functions. The **PSP_FILE_CALLBACK** type defines a pointer to this callback function. *FileCallback* is a placeholder for the application-defined function name.

For more information, see
[Notifications](https://learn.microsoft.com/windows/desktop/SetupApi/notifications),
[Creating a Custom Queue Callback Routine](https://learn.microsoft.com/windows/desktop/SetupApi/creating-a-custom-queue-callback-routine), and
[Creating a Cabinet Callback Routine](https://learn.microsoft.com/windows/desktop/SetupApi/creating-a-cabinet-callback-routine).

## Parameters

### `Context`

The context information about the queue notification that is returned to the callback function.

### `Notification`

The event that triggers the call to the callback function.

### `Param1`

The additional notification information. The value is dependent on the notification that is being returned.

### `Param2`

The additional notification information. The value is dependent on the notification that is being returned.

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea)

[SetupInstallFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfilea)

[SetupInstallFileEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfileexa)

[SetupInstallFromInfSection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallfrominfsectiona)

[SetupIterateCabinet](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupiteratecabineta)