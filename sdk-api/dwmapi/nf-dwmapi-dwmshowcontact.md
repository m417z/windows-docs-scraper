# DwmShowContact function

## Description

Called by an app or framework to specify the visual feedback type to draw in response to a particular touch or pen contact.

## Parameters

### `dwPointerID` [in]

The pointer ID of the contact. Each touch or pen contact is given a unique ID when it is detected.

### `eShowContact` [in]

One or more of the following DWM_SHOWCONTACT visualizations that DWM should show for this contact.

#### DWMSC_NONE (0x00000000)

No visual feedback should be shown in response to the contact.

#### DWMSC_DOWN (0x00000001)

Show the "contact down" animation, such as would be used in a button press.

#### DWMSC_UP (0x00000002)

Show the "contact up" animation, such as would be used in a button release.

#### DWMSC_DRAG (0x00000004)

Show the "contact drag" animation when the UI element that was selected by the touch or pen is dragged.

#### DWMSC_HOLD (0x00000008)

Show a visual while the contact is held down, such as holding down a button.

#### DWMSC_PENBARREL (0x00000010)

Show the pen barrel visual when the pen barrel button is pressed.

#### DWMSC_ALL (0xFFFFFFFF)

Show any of the animations if called for.

## Return value

If *dwPointerID* does not match that of a contact currently present on the screen, this function returns E_INVALIDARG; otherwise, it returns S_OK.

## Remarks

It is safe to call this function on the UI thread.