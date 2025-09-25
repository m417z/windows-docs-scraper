# OleUIAddVerbMenuA function

## Description

Adds the **Verb** menu for the specified object to the specified menu.

## Parameters

### `lpOleObj` [in, optional]

Pointer to the [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) interface on the selected object. If this is **NULL**, then a default disabled menu item is created.

### `lpszShortType` [in, optional]

Pointer to the short name defined in the registry (AuxName==2) for the object identified with *lpOleObj*. If the string is not known, then **NULL** may be passed. If **NULL** is passed, [IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype) is called to retrieve it. If the caller has easy access to the string, it is faster to pass it in.

### `hMenu` [in]

Handle to the menu in which to make modifications.

### `uPos` [in]

Position of the menu item.

### `uIDVerbMin` [in]

The identifier value at which to start the verbs.

### `uIDVerbMax` [in]

 The maximum identifier value to be used for object verbs. If *uIDVerbMax* is 0, then no maximum identifier value is used.

### `bAddConvert` [in]

 Indicates whether to add a **Convert** item to the bottom of the menu (preceded by a separator).

### `idConvert` [in]

The identifier value to use for the **Convert** menu item, if *bAddConvert* is **TRUE**.

### `lphMenu` [out]

An **HMENU** pointer to the cascading verb menu if it's created. If there is only one verb, this will be filled with **NULL**.

## Return value

This function returns **TRUE** if *lpOleObj* was valid and at least one verb was added to the menu. A **FALSE** return indicates that *lpOleObj* was **NULL** and a disabled default menu item was created.

## Remarks

If the object has one verb, the verb is added directly to the given menu.

> [!NOTE]
> The oledlg.h header defines OleUIAddVerbMenu as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).