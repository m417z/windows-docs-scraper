# BANDSITEINFO structure

## Description

Contains information about a band site. This structure is used with the [IBandSite::GetBandSiteInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ibandsite-getbandsiteinfo) and [IBandSite::SetBandSiteInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ibandsite-setbandsiteinfo) methods.

## Members

### `dwMask`

Type: **DWORD**

The mask values that determine the other fields in this structure that are being requested or set.

#### BSIM_STATE

The **dwState** value is being requested or set.

#### BSIM_STYLE

The **dwStyle** value is being requested or set.

### `dwState`

Type: **DWORD**

Bits that specify the state of the band.

#### BSSF_VISIBLE

The band is visible.

#### BSSF_NOTITLE

The band's title is not shown.

#### BSSF_UNDELETEABLE

The band cannot be deleted.

### `dwStyle`

Type: **DWORD**

Bit flags that specify the style of the band.

#### BSIS_AUTOGRIPPER

Show the gripper if the band is neither fixed in size nor floating.

#### BSIS_NOGRIPPER

Equivalent to RBBS_NOGRIPPER.

#### BSIS_ALWAYSGRIPPER

Equivalent to RBBS_GRIPPERALWAYS.

#### BSIS_LEFTALIGN

Equivalent to RBBS_VERTICALGRIPPER.

#### BSIS_SINGLECLICK

Opposite to RBBS_DBLCLKTOGGLE.

#### BSIS_NOCONTEXTMENU

Disables the band-specific context menu (typically "Close Toolbar").

#### BSIS_NODROPTARGET

Prevents wrapping of the [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface provided by the band.

#### BSIS_NOCAPTION

Hides the band caption text.

#### BSIS_PREFERNOLINEBREAK

Sets the fAutoBreak member of NMREBARAUTOBREAK to specify the preference of no line break.

#### BSIS_LOCKED

Removes the "Close Toolbar" and "Show Title" choices from the menu.

#### BSIS_PRESERVEORDERDURINGLAYOUT (0x00000200)

**Internet Explorer 7 and later**. Preserves the order of items during layout.

#### BSIS_FIXEDORDER (0x00000400)

**Internet Explorer 7 and later**. Prevents items from being reordered.