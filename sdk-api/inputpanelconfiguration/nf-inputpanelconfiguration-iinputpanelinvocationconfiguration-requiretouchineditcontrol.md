# IInputPanelInvocationConfiguration::RequireTouchInEditControl

## Description

Requires an explicit user tap in an edit field before the touch keyboard invokes.

## Return value

The **RequireTouchInEditControl** method always returns **S_OK**.

## Remarks

When the **RequireTouchInEditControl** method is called, all future focus changes require an explicit user tap in an edit field before the touch keyboard invokes. You can call the **RequireTouchInEditControl** method multiple times, but there's no way to undo the setting.

This setting applies for any focus event that takes place to a window that is running in the process that called it. The **RequireTouchInEditControl** method doesn't affect owned windows in another process that have an ownership chain to the current process that called **RequireTouchInEditControl**.

The **RequireTouchInEditControl** method always returns **S_OK**. If this API is used, then the **IsUIBusy** property has no effect. The two interaction models are essentially mutually exclusive.

The following code shows how to call the **RequireTouchInEditControl** method.

```cpp
#include <inputpanelconfiguration.h>
#include <inputpanelconfiguration_i.c>

IInputPanelInvocationConfiguration *pInputPanelInvocationConfiguration;
CoCreateInstance(CLSID_InputPanelConfiguration, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pInputPanelInvocationConfiguration));
pInputPanelInvocationConfiguration->RequireTouchInEditControl();

```

**Note** Calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) before the app finishes drawing UI can cause undefined behavior. If the touch keyboard isn't already running, calling **Release** could cause tiptsf.dll to be unloaded, because there are no more references to the dll. If this occurs, the state set by the **RequireTouchInEditControl** method is lost.

If you need to delay the invocation of the touch keyboard until a later time, like when animations or direct manipulation have completed, use the **IsUIBusy** custom UI automation property. For more info, see [Registering Custom Properties, Events, and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-regcustompropseventpatterns).

When you set **IsUIBusy** to **True**, the touch keyboard doesn't change visual state based on focus changes within the app. It's still able to change visual state based on overriding user action, like using a physical keyboard or manual dismissal.

When you set **IsUIBusy** to **False**, the touch keyboard resumes its default behavior and queries synchronously for the control that has focus.

The following code shows how to register the **IsUIBusy** custom UI automation property.

```cpp
/* 03391bea-6681-474b-955c-60f664397ac6 */
DEFINE_GUID(
    GUID_UIBusy,
    0x03391bea, 0x6681, 0x474b, 0x95, 0x5c, 0x60, 0xf6, 0x64, 0x39, 0x7a, 0xc6);

UIAutomationPropertyInfo customPropertyInfo =
            {
                GUID_UIBusy,
                L"IsUIBusy",
                UIAutomationType_Bool
            };

            CComPtr<IUIAutomationRegistrar> spRegistrar;
            hr = spRegistrar.CoCreateInstance(
                CLSID_CUIAutomationRegistrar,
                nullptr,
                CLSCTX_INPROC_SERVER);
            if (SUCCEEDED(hr))
            {
                PATTERNID customPropertyId;
                hr = spRegistrar->RegisterProperty(&customPropertyInfo, &customPropertyId);
            }

```

## See also

[IInputPanelInvocationConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelinvocationconfiguration)