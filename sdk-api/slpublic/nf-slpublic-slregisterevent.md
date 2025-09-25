# SLRegisterEvent function

## Description

 Registers an event in the SL service. The caller can receive notifications when the registered event is fired.

## Parameters

### `hSLC` [in, optional]

Type: **HSLC**

The handle to the current SLC session.

### `pwszEventId` [in]

Type: **PCWSTR**

The predefined SL event identifier.

### `pApplicationId` [in]

Type: **const SLID***

A pointer to the application ID to which the event will be registered.

### `hEvent` [in]

Type: **HANDLE**

 The event handle used for notification.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **SL_E_INVALID_EVENT_ID**<br><br>0xC004F019 | The requested event ID is not valid. |