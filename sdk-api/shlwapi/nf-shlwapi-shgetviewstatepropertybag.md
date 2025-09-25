# SHGetViewStatePropertyBag function

## Description

[**SHGetViewStatePropertyBag** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Retrieves a property bag in which the view state information for a folder can be stored and subsequently retrieved. The user's settings are kept for the next time the user visits the folder.

## Parameters

### `pidl` [in, optional]

Type: **PCIDLIST_ABSOLUTE**

A PIDL of the folder for which you are requesting properties. This parameter must be **NULL** if the SHGVSPB_ALLFOLDERS flag is passed.

### `pszBagName` [in, optional]

Type: **PCWSTR**

A pointer to a string that contains the name of the requested property bag.

### `dwFlags`

Type: **DWORD**

A value that specifies a combination of the following flags.

One value from the following set of flags is required.

#### SHGVSPB_PERUSER

Returns the per-user properties for the specified *pidl*.

#### SHGVSPB_ALLUSERS

Returns the All User properties for the specified *pidl*.

One value from the following set of flags is required.

#### SHGVSPB_PERFOLDER

Returns the property bag for the folder specified by the *pidl* parameter.

#### SHGVSPB_ALLFOLDERS

Returns the property bag that applies to all folders.

#### SHGVSPB_INHERIT

Returns the property bag used to provide defaults for subfolders that do not have their property bag.

The following flags are optional.

#### SHGVSPB_ROAM

Allows the property bag to roam. See [Roaming User Profiles](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776897(v=vs.85)). This flag cannot be combined with SHGVSPB_ALLFOLDERS.

#### SHGVSPB_NOAUTODEFAULTS

Suppresses the search for a suitable default when the property bag cannot be found for the specified folder. By default, if SHGVSPB_INHERIT is not specified and a property bag cannot be found for the specified folder, the system searches for identically named property bags in other locations that may be able to provide default values. For example, the system searches in the ancestors of the folder to see if any of them provide a SHGVSPB_INHERIT property bag. Other places the system searches are in the user defaults and the global defaults.

The following set of flags consists of values that combine some flags listed above, and are used for brevity and convenience.

#### SHGVSPB_FOLDER

Combines SHGVSPB_PERUSER and SHGVSPB_PERFOLDER.

#### SHGVSPB_FOLDERNODEFAULTS

Combines SHGVSPB_PERUSER, SHGVSPB_PERFOLDER, and SHGVSPB_NOAUTODEFAULTS.

#### SHGVSPB_USERDEFAULTS

Combines SHGVSPB_PERUSER and SHGVSPB_ALLFOLDERS.

#### SHGVSPB_GLOBALDEFAULTS

Combines SHGVSPB_ALLUSERS and SHGVSPB_ALLFOLDERS.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is named SHGVSPB_GLOBALDEAFAULTS.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Critical information should not be stored in the view state property bag because the system keeps only a limited number of view states. If a folder is not visited for a long time, its view state is eventually deleted.

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.