# IRendezvousApplication::SetRendezvousSession

## Description

Passes [IRendezvousSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/rendezvoussession/nn-rendezvoussession-irendezvoussession) to the Windows Remote Assistance application. This method is used by the instant messaging application.

## Parameters

### `pRendezvousSession` [in]

[IRendezvousSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/rendezvoussession/nn-rendezvoussession-irendezvoussession)

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The [IRendezvousSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/rendezvoussession/nn-rendezvoussession-irendezvoussession) was passed to the Windows Remote Assistance application successfully. |
| **E_INVALIDARG** | The session object passed to the method is not valid. |
| **E_FAIL** | A catastrophic error occurred while trying to pass the session to the Windows Remote Assistance application. |