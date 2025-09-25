# IViewHelper::GetProceedOnNewConfiguration

## Description

The **GetProceedOnNewConfiguration** method allows the user-mode display driver to suppress the TMM user interface and display changing actions on a new, two-monitor configuration. This is only the case when a user presses a keyboard shortcut to switch views (such as, FN key combinations like FN, F5) and causes a Hot Plug Detection (HPD) event to occur.

## Return value

The **GetProceedOnNewConfiguration** method returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The TMM user interface can appear.<br><br>TMM proceeds with its operations, defaulting to clone view if the current display configuration is in single view. TMM will also open a dialog. |
| **S_FALSE** | Both TMM actions and user interface should be suppressed.<br><br>TMM will not actively change any display settings and will not show a user interface. The only conditions under which returning S_FALSE are allowed are:<br><br>* The state change for displays was caused by a user pressing a keyboard shortcut (that is, Fn key combinations). For example, if the user presses a keyboard shortcut to switch views, the user-mode display driver might have its own user interface to present to the user. In this situation, if the user-mode display driver must suppress TMM actions, this return code can be used to inform TMM.<br>* The state change for displays was caused by user input from the user-mode display driver's user interface. For example, if the user opens a program that was created by the hardware vendor to manually change the connected and active state, an HPD might be generated. In this situation, this return code will prevent TMM from taking action and conflicting with the user's manual input. The driver will then handle the display change. |
| **S_INIT** | Only TMM actions are suppressed. However, TMM user interface is shown.<br><br>TMM will not actively change any display settings but can show its user interface. The user-mode display driver has the opportunity to set predefined configurations. However, TMM user interface can still be shown, which allows users to customize the display settings if they do not like the default. |

## Remarks

**GetProceedOnNewConfiguration** is called only when an HPD event occurs and TMM encounters a new configuration (that is, a configuration for which TMM does not yet have a profile).