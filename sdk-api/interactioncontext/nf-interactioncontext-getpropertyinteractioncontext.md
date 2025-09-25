# GetPropertyInteractionContext function

## Description

Gets [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object properties.

## Parameters

### `interactionContext` [in]

Handle to the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

### `contextProperty` [in]

One of the constants identified by [INTERACTION_CONTEXT_PROPERTY enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-interaction_context_property).

### `value` [out]

The value of the property.

Valid values for *contextProperty* are:

|||
|--- |--- |
|**INTERACTION_CONTEXT_PROPERTY_MEASUREMENT_UNITS_HIMETRIC**<br>0|Measurement units are HIMETRIC units (0.01 mm).|
|**INTERACTION_CONTEXT_PROPERTY_MEASUREMENT_UNITS_SCREEN**<br>1|Measurement units are screen pixels. This is the default value.|
|**INTERACTION_CONTEXT_PROPERTY_UI_FEEDBACK_OFF**<br>0|Visual feedback for user interactions is disabled (the caller is responsible for displaying visual feedback). For more info, see [GetWindowFeedbackSetting function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getwindowfeedbacksetting) and [SetWindowFeedbackSetting function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowfeedbacksetting)|
|**INTERACTION_CONTEXT_PROPERTY_UI_FEEDBACK_ON**<br>1|Visual feedback for user interactions is enabled. This is the default value. For more info, see [GetWindowFeedbackSetting function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getwindowfeedbacksetting) and [SetWindowFeedbackSetting function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowfeedbacksetting).|
|**INTERACTION_CONTEXT_PROPERTY_FILTER_POINTERS_OFF**<br>0|Pointer filtering is disabled (all pointer input data is processed).|
|**INTERACTION_CONTEXT_PROPERTY_FILTER_POINTERS_ON**<br>1|Pointer filtering is enabled (only pointers specified through the [AddPointerInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-addpointerinteractioncontext) are processed). This is the default value. |

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also

[SetPropertyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setpropertyinteractioncontext)