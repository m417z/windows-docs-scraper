# SHLoadNonloadedIconOverlayIdentifiers function

## Description

Signals the Shell that during the next operation requiring overlay information, it should load icon overlay identifiers that either failed creation or were not present for creation at startup. Identifiers that have already been loaded are not affected.

## Return value

Type: **HRESULT**

Always returns S_OK.

## Remarks

A call to **SHLoadNonloadedIconOverlayIdentifiers** does not result in the immediate loading of a Shell extension, nor does it cause an icon overlay handler to be loaded. A call to **SHLoadNonloadedIconOverlayIdentifiers** results in a situation such that the next code to ask for icon overlay information triggers a comparison of icon overlays in the registry to those that are already loaded. If an icon overlay is newly registered and the system has not already reached its upper limit of fifteen icon overlays, the new overlay is loaded. **SHLoadNonloadedIconOverlayIdentifiers** alone does not load a new icon overlay; you also need to trigger an action that uses the overlay, such as a refresh of a Windows Explorer view.

For more information, see [How to Implement Icon Overlay Handlers](https://learn.microsoft.com/windows/desktop/shell/how-to-implement-icon-overlay-handlers).