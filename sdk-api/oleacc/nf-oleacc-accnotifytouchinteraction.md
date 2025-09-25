# AccNotifyTouchInteraction function

## Description

Allows an assistive technology (AT) application to notify the system that it is interacting with UI through a Windows Automation API (such as Microsoft UI Automation) as a result of a touch gesture from the user. This allows the assistive technology to notify the target application and the system that the user is interacting with touch.

## Parameters

### `hwndApp` [in]

A window that belongs to the AT process that is calling **AccNotifyTouchInteraction**.

### `hwndTarget` [in]

The nearest window of the automation element that the AT is targeting.

### `ptTarget` [in]

The center point of the automation element (or a point in the bounding rectangle of the element).

## Return value

If successful, returns S_OK.

If not successful, returns a standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

## Remarks

This function requires the calling process to have UIAccess or higher privileges. If the caller does not have the required privileges, the call to **AccNotifyTouchInteraction** fails and returns **E_ACCESSDENIED**. For more information, see [Security Considerations for Assistive Technologies](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-securityoverview) and [/MANIFESTUAC (Embeds UAC information in manifest)](https://learn.microsoft.com/cpp/build/reference/manifestuac-embeds-uac-information-in-manifest).

When an AT is consuming touch data (such as when using the [RegisterPointerInputTarget](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerpointerinputtarget) function), the shell and applications that the AT interacts with through the Windows Automation API are not aware that the user is interacting through touch. For the system to expose touch-related functionality to the user, the AT must use **AccNotifyTouchInteraction** to notify the system that it is performing the interaction in response to user touch input.

#### Examples

This code example shows how to call the **AccNotifyTouchInteraction** function.

```cpp
// pTargetElement is the element being interacted with by the user, hwndApp
// represents an HWND owned by the AT.
HRESULT PerformTouchBasedInteraction(IUIAutomationElement *pTargetElement,
        HWND hwndApp)
{
    HRESULT hr = S_OK;

    // Set the focus to the element and then notify the system that the
    // interaction is occurring due to a touch gesture. This would also apply
    // to pattern-based interactions (such as calls to
    // IUIAutomationInvokePattern::Invoke)
    hr = pTargetElement->SetFocus();
    if (SUCCEEDED(hr))
    {
        HWND hwndTarget;
        POINT ptTarget;
        BOOL fGotClickablePoint;

        // If the current element does not have a native window handle, an
        // alternate method (such as walking up the parent chain) is required
        // to get the nearest valid HWND.
        hr = pTargetElement->get_CurrentNativeWindowHandle((UIA_HWND *)(&hwndTarget));
        if (SUCCEEDED(hr))
        {
            // If the provider doesn't return a clickable point, an alternate
            // method (such as using the bounding rectangle) will be required
            // to get the center point of the current element.
            hr = pTargetElement->GetClickablePoint(&ptTarget, &fGotClickablePoint);
        }

        if (SUCCEEDED(hr) && fGotClickablePoint)
        {
            hr = AccNotifyTouchInteraction(hwndApp, hwndTarget, ptTarget);
        }
    }

    return hr;
}
```

## See also

[AccSetRunningUtilityState](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-accsetrunningutilitystate)

[RegisterPointerInputTarget](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerpointerinputtarget)

[UnregisterPointerInputTarget](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterpointerinputtarget)