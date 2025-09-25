# SLFireEvent function

## Description

Sends a specified event to a registered listener.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pwszEventId` [in]

Type: **PCWSTR**

The ID of the event to be fired.

### `pApplicationId` [in]

Type: **const SLID***

A pointer to the application ID.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_ACCESSDENIED**<br><br>0x80070005 | Access denied (API requires admin privileges). |
| **SL_E_INVALID_EVENT_ID**<br><br>0xC004F019 | The requested event ID is not valid. |
| **SL_E_EVENT_NOT_REGISTERED**<br><br>0xC004F01A | The requested event is not registered with the service. |