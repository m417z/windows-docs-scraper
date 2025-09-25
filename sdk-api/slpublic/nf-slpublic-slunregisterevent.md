# SLUnregisterEvent function

## Description

Unregisters a registered event in the SL service.

## Parameters

### `hSLC` [in, optional]

Type: **HSLC**

The handle to the current SLC session.

### `pwszEventId` [in]

Type: **PCWSTR**

The predefined SL event identifier that will be unregistered.

### `pApplicationId` [in]

Type: **const SLID***

A pointer to the application ID that the event will be unregistered from.

### `hEvent` [in]

Type: **HANDLE**

The registered event handle.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_INVALID_EVENT_ID**<br><br>0xC004F019 | The requested event ID is not valid. |
| **SL_E_EVENT_NOT_REGISTERED**<br><br>0xC004F01A | The requested event is not registered with the service. |