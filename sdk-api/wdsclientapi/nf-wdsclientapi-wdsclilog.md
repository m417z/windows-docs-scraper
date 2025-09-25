# WdsCliLog function

## Description

Sends a log event to the WDS server.

## Parameters

### `hSession` [in]

A handle to a session with a WDS server. This was a handle returned by
the [WdsCliCreateSession](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicreatesession) function.

### `ulLogLevel` [in]

Indicates the threshold severity required to log an event. The WDS server will log events only if the server log level is greater
than or equal to the value specified.

This parameter can have one of the following values.

#### WDS_LOG_LEVEL_DISABLED (0)

#### WDS_LOG_LEVEL_ERROR (1)

#### WDS_LOG_LEVEL_WARNING (2)

#### WDS_LOG_LEVEL_INFO (3)

### `ulMessageCode` [in]

The type of message that is being logged.

| Value | Meaning |
| --- | --- |
| **WDS_LOG_TYPE_CLIENT_ERROR**<br><br>1 | A client error message. An additional parameter of type **PWSTR** that describes the error is required. |
| **WDS_LOG_TYPE_CLIENT_STARTED**<br><br>2 | A client started message. No additional parameters are required. |
| **WDS_LOG_TYPE_CLIENT_FINISHED**<br><br>3 | A client finished message. No additional parameters are required. |
| **WDS_LOG_TYPE_CLIENT_IMAGE_SELECTED**<br><br>4 | A client image selected message. Two additional parameters of type **PWSTR** are required. The first is the Image Name and the second is the Group Name. |
| **WDS_LOG_TYPE_CLIENT_APPLY_STARTED**<br><br>5 | No additional parameters are required. |
| **WDS_LOG_TYPE_CLIENT_APPLY_FINISHED**<br><br>6 | No additional parameters are required. |
| **WDS_LOG_TYPE_CLIENT_GENERIC_MESSAGE**<br><br>7 | A generic message. An additional parameter of type **PWSTR** that contains the message is required. |
| **WDS_LOG_TYPE_CLIENT_MAX_CODE**<br><br>8 | Used to determine an out-of-range index. Values greater than or equal to **WDS_LOG_TYPE_CLIENT_MAX_CODE** are not valid. |

### `...`

The quantity and type of the additional arguments varies with the value of the
*ulMessageCode* parameter.

## Return value

If the function succeeds, the return is **S_OK**.

## See also

[WdsCliCreateSession](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicreatesession)

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)