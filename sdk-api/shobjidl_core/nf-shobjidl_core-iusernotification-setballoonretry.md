# IUserNotification::SetBalloonRetry

## Description

Specifies the conditions for trying to display user information when the first attempt fails.

## Parameters

### `dwShowTime` [in]

Type: **DWORD**

The amount of time, in milliseconds, to display the user information.

### `dwInterval` [in]

Type: **DWORD**

The interval of time, in milliseconds, between attempts to display the user information.

### `cRetryCount` [in]

Type: **UINT**

The number of times the system should try to display the user information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.