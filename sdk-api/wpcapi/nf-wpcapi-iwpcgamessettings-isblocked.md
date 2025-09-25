# IWPCGamesSettings::IsBlocked

## Description

Determines whether the specified game is blocked from execution.

## Parameters

### `guidAppID` [in]

The GUID associated with the game during install or game scan detection.

### `pdwReasons` [out]

The reason code. For a list of values, see the [WPCFLAG_ISBLOCKED](https://learn.microsoft.com/windows/desktop/api/wpcevent/ne-wpcevent-wpcflag_isblocked) enumeration.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

If *guidAppID* is not found, the policy will default to unrated and set **pdwReasons* to WPCFLAG_ISBLOCKED_NOT_BLOCKED.

## See also

[IWPCGamesSettings](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcgamessettings)