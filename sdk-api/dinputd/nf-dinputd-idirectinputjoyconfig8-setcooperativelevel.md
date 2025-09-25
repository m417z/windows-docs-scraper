# IDirectInputJoyConfig8::SetCooperativeLevel

## Description

The **IDirectInputJoyConfig8::SetCooperativeLevel**  method establishes the cooperation level for the instance of the device. The only cooperative levels supported for the **IDirectInputJoyConfig8** interface are DISCL_EXCLUSIVE and DISCL_BACKGROUND.

## Parameters

### `unnamedParam1`

Handle to the window associated with the interface. This parameter must be non-NULL and must be a top-level window. It is an error to destroy the window while it is still associated with an **IDirectInputJoyConfig8** interface.

### `unnamedParam2`

Specifies one of a set of flags that describe the level of cooperation associated with the device. The value must be DISCL_EXCLUSIVE | DISCL_BACKGROUND.

## Return value

Returns DI_OK if successful; otherwise, returns the following COM error value (this value is intended to be illustrative and is not necessarily comprehensive):

| Return code | Description |
| --- | --- |
| **DIERR_INVALIDPARAM** | One or more parameters was invalid. |