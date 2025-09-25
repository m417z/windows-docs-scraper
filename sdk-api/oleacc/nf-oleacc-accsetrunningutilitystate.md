# AccSetRunningUtilityState function

## Description

Sets system values that indicate whether an assistive technology (AT) application's current state affects functionality that is typically provided by the system.

## Parameters

### `hwndApp` [in]

Type: **HWND**

The handle of the AT application window. This parameter must not be **NULL**.

### `dwUtilityStateMask` [in]

Type: **DWORD**

A
mask that indicates the system values being set. It can be a combination of the following values:

#### ANRUS_ON_SCREEN_KEYBOARD_ACTIVE

#### ANRUS_TOUCH_MODIFICATION_ACTIVE

#### ANRUS_PRIORITY_AUDIO_ACTIVE

#### ANRUS_PRIORITY_AUDIO_ACTIVE_NODUCK

### `dwUtilityState` [in]

Type: **DWORD**

The new settings for the system values indicated by *dwUtilityStateMask*. This parameter can be zero to reset the system values, or a combination of the following values.

| Value | Meaning |
| --- | --- |
| **ANRUS_ON_SCREEN_KEYBOARD_ACTIVE**<br><br>0x0000001 | The AT application is providing an on-screen keyboard. |
| **ANRUS_TOUCH_MODIFICATION_ACTIVE**<br><br>0x0000002 | The AT application is consuming redirected touch input. |
| **ANRUS_PRIORITY_AUDIO_ACTIVE**<br><br>0x0000004 | The AT application is relying on audio (such as text-to-speech) to convey essential information to the user and should remain audible over other system sounds. |
| **ANRUS_PRIORITY_AUDIO_ACTIVE_NODUCK**<br><br>0x0000008 | The AT application is relying on audio (such as text-to-speech) to convey essential information to the user but should not change relative to other system sounds. |

## Return value

Type: **STDAPI**

If successful, returns S_OK.

If not successful, returns a standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

## Remarks

Before it exits, an AT application should reset any system values that it previously set.

This function requires the calling process to have UIAccess or higher privileges. If the caller does not have the required privileges, the call to **AccSetRunningUtilityState** fails and returns **E_ACCESSDENIED**. For more information, see [Security Considerations for Assistive Technologies](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-securityoverview) and [/MANIFESTUAC (Embeds UAC information in manifest)](https://learn.microsoft.com/cpp/build/reference/manifestuac-embeds-uac-information-in-manifest).

#### Examples

This code example shows how to call the **AccSetRunningUtilityState** function.

```cpp
if (SUCCEEDED(hr))
{
    // Tell the system that an AT application has registered with the
    // touch redirector.
    hr = AccSetRunningUtilityState(hwndTouchWindow,
            ANRUS_TOUCH_MODIFICATION_ACTIVE,
            ANRUS_TOUCH_MODIFICATION_ACTIVE);
    if (FAILED(hr))
    {
        MyErrorHandler(hr); // Application-defined error handler
    }
}

```

## See also

[Security Considerations for Assistive Technologies](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-securityoverview)