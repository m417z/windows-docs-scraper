# DESKBANDINFO structure

## Description

Receives information about a band object. This structure is used with the deprecated [IDeskBand::GetBandInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ideskband-getbandinfo) method.

## Members

### `dwMask`

Type: **DWORD**

The set of flags that determine which members of this structure are being requested by the caller. One or more of the following values:

#### DBIM_MINSIZE

**ptMinSize** is requested.

#### DBIM_MAXSIZE

**ptMaxSize** is requested.

#### DBIM_INTEGRAL

**ptIntegral** is requested.

#### DBIM_ACTUAL

**ptActual** is requested.

#### DBIM_TITLE

**wszTitle** is requested.

#### DBIM_MODEFLAGS

**dwModeFlags** is requested.

#### DBIM_BKCOLOR

**crBkgnd** is requested.

### `ptMinSize`

Type: **[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)**

A [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure that receives the minimum size of the band object. The minimum width is given in the **POINTL** structure's **x** member and the minimum height is given in the **y** member.

### `ptMaxSize`

Type: **[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)**

A [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure that receives the maximum size of the band object. The maximum height is given in the **POINTL** structure's **y** member and the **x** member is ignored. If the band object has no limit for its maximum height, (LONG)-1 should be used.

### `ptIntegral`

Type: **[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)**

A [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure that receives the sizing step value (increment) in which the band object is resized. The vertical step value is given in the **POINTL** structure's **y** member and the **x** member is ignored.

The **dwModeFlags** member must contain the DBIMF_VARIABLEHEIGHT flag; otherwise, **ptIntegral** is ignored.

### `ptActual`

Type: **[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)**

A [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure that receives the ideal size of the band object. The ideal width is given in the **POINTL** structure's **x** member and the ideal height is given in the **y** member. The band container attempts to use these values, but the band is not guaranteed to be this size.

### `wszTitle`

Type: **WCHAR[256]**

A **WCHAR** buffer that receives the title of the band.

### `dwModeFlags`

Type: **DWORD**

A value that receives a set of flags that specify the mode of operation for the band object. One or more of the following values:

#### DBIMF_NORMAL

The band uses default properties. The other mode flags modify this flag.

#### DBIMF_FIXED

**Windows XP and later:** The band object is of a fixed sized and position. With this flag, a sizing grip is not displayed on the band object.

#### DBIMF_FIXEDBMP

**Windows XP and later:** The band object uses a fixed bitmap (.bmp) file as its background. Note that backgrounds are not supported in all cases, so the bitmap may not be seen even when this flag is set.

#### DBIMF_VARIABLEHEIGHT

The height of the band object can be changed. The **ptIntegral** member defines the step value by which the band object can be resized.

#### DBIMF_UNDELETEABLE

**Windows XP and later:** The band object cannot be removed from the band container.

#### DBIMF_DEBOSSED

The band object is displayed with a sunken appearance.

#### DBIMF_BKCOLOR

The band is displayed with the background color specified in **crBkgnd**.

#### DBIMF_USECHEVRON

**Windows XP and later:** If the full band object cannot be displayed (that is, the band object is smaller than **ptActual**, a chevron is shown to indicate that there are more options available. These options are displayed when the chevron is clicked.

#### DBIMF_BREAK

**Windows XP and later:** The band object is displayed in a new row in the band container.

#### DBIMF_ADDTOFRONT

**Windows XP and later:** The band object is the first object in the band container.

#### DBIMF_TOPALIGN

**Windows XP and later:** The band object is displayed in the top row of the band container.

#### DBIMF_NOGRIPPER

**Windows Vista and later:** No sizing grip is ever displayed to allow the user to move or resize the band object.

#### DBIMF_ALWAYSGRIPPER

**Windows Vista and later:** A sizing grip that allows the user to move or resize the band object is always shown, even if that band object is the only one in the container.

#### DBIMF_NOMARGINS

**Windows Vista and later:** The band object should not display margins.

### `crBkgnd`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

A [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) structure that receives the background color of the band. The **dwModeFlags** member must contain the **DBIMF_BKCOLOR** flag; otherwise, **crBkgnd** is ignored.