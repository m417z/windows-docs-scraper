# SLReArm function

## Description

This function is rearm application activation.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pApplicationId` [in]

Type: **const SLID***

A pointer to the application ID.

### `pProductSkuId` [in, optional]

Type: **const SLID***

A pointer to the product SKU ID.

### `dwFlags` [in]

Type: **DWORD**

Flags for ReArm behavior. Valid values are 0 or
**SL_REARM_REBOOT_REQUIRED**. Passing **SL_REARM_REBOOT_REQUIRED** will
require a reboot before a function using the security processor can
succeed.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |