# OPENCARDNAME_EXA structure

## Description

The **OPENCARDNAME_EX** structure contains the information that the
[SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda) function uses to initialize a smart card **Select Card** dialog box.

## Members

### `dwStructSize`

The length, in bytes, of the structure. The value of this member must not be **NULL**.

### `hSCardContext`

The context used for communication with the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). Call
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) to set the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) and
[SCardReleaseContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreleasecontext) to release it. The value of this member must not be **NULL**.

### `hwndOwner`

The window that owns the dialog box. This member can be any valid window handle, or it can be **NULL** for the desktop default.

### `dwFlags`

A set of bit flags that you can use to initialize the dialog box. When the dialog box returns, it sets these flags to indicate the user's input. This member can be one of the following flags.

| Value | Meaning |
| --- | --- |
| **SC_DLG_MINIMAL_UI** | Display the dialog box only if the card being searched for by the calling application is not located and available for use in a reader. This allows the card to be found, connected (either through the internal dialog box mechanism or the user callback functions), and returned to the calling application. |
| **SC_DLG_NO_UI** | Force no display of the **Select Card** [user interface](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UI), regardless of search outcome. |
| **SC_DLG_FORCE_UI** | Force display of the **Select Card** UI, regardless of the search outcome. |

### `lpstrTitle`

A pointer to a string to be placed in the title bar of the dialog box. If this member is **NULL**, the system uses the default title "Select Card:".

### `lpstrSearchDesc`

A pointer to a string to be displayed to the user as a prompt to insert the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). If this member is **NULL**, the system uses the default text "Please insert a smart card".

### `hIcon`

A handle to an icon (32 x 32 pixels). You can specify a vendor-specific icon to display in the dialog box. If this value is **NULL**, a generic, smart card reader–loaded icon is displayed.

### `pOpenCardSearchCriteria`

A pointer to the
[OPENCARD_SEARCH_CRITERIA](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-opencard_search_criteriaa) structure to be used, or **NULL**, if one is not used.

### `lpfnConnect`

A pointer to the caller's card connect routine. If the caller needs to perform additional processing to connect to the card, this function pointer is set to the user's connect function. If the connect function is successful, the card is left connected and initialized, and the card handle is returned.

The prototype for the connect routine is as follows.

```cpp
Connect(
  hSCardContext,  // the card context passed in the parameter block
  szReader,       // the name of the reader
  mszCards,       // multiple string that contains the possible
                  //  card names in the reader
  pvUserData      // pointer to user data passed in parameter block
);

```

### `pvUserData`

A void pointer to user data. This pointer is passed back to the caller on the Connect routine.

### `dwShareMode`

If **lpfnConnect** is not **NULL**, the **dwShareMode** and **dwPreferredProtocols** members are ignored. If **lpfnConnect** is **NULL** and **dwShareMode** is nonzero, an internal call is made to
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta) that uses **dwShareMode** and **dwPreferredProtocols** as the *dwShareMode* and *dwPreferredProtocols* parameters. If the connect succeeds, **hCardHandle** is set to the handle returned by **SCardConnect**. If **lpfnConnect** is **NULL** and **dwShareMode** is zero, **hCardHandle** is set to **NULL**.

### `dwPreferredProtocols`

Used for internal connection as described in **dwShareMode**.

### `lpstrRdr`

If the card is located, the **lpstrRdr** buffer contains the name of the reader that contains the located card. The buffer should be at least 256 characters long.

### `nMaxRdr`

Size, in bytes (ANSI version) or characters ([Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) version), of the buffer pointed to by **lpstrRdr**. If the buffer is too small to contain the reader information,
[SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda) returns SCARD_E_NO_MEMORY and the required size of the buffer pointed to by **lpstrRdr**.

### `lpstrCard`

If the card is located, the *lpstrCard* buffer contains the name of the located card. The buffer should be at least 256 characters long.

### `nMaxCard`

Size, in bytes (ANSI version) or characters ([Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) version), of the buffer pointed to by *lpstrCard*. If the buffer is too small to contain the card information,
[SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda) returns SCARD_E_NO_MEMORY and the required size of the buffer in **nMaxCard**.

### `dwActiveProtocol`

The actual protocol in use when the dialog box makes a connection to a card.

### `hCardHandle`

A handle of the connected card (either through an internal dialog box connect or an **lpfnConnect** callback).

## See also

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardReleaseContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreleasecontext)

[SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda)

[Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values)

## Remarks

> [!NOTE]
> The winscard.h header defines OPENCARDNAME_EX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).