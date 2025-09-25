# ITextDocument2::GetPreferredFont

## Description

Retrieves the preferred font for a particular character repertoire and character position.

## Parameters

### `cp` [in]

Type: **long**

The character position for the preferred font.

### `CharRep` [in]

Type: **long**

The character repertoire index for the preferred font. It can be one of the following values.

#### tomAboriginal

#### tomAnsi

#### tomArabic

#### tomArmenian

#### tomBaltic

#### tomBengali

#### tomBIG5

#### tomBraille

#### tomCherokee

#### tomCyrillic

#### tomDefaultCharRep

#### tomDevanagari

#### tomEastEurope

#### tomEmoji

#### tomEthiopic

#### tomGB2312

#### tomGeorgian

#### tomGreek

#### tomGujarati

#### tomGurmukhi

#### tomHangul

#### tomHebrew

#### tomJamo

#### tomKannada

#### tomKayahli

#### tomKharoshthi

#### tomKhmer

#### tomLao

#### tomLimbu

#### tomMac

#### tomMalayalam

#### tomMongolian

#### tomMyanmar

#### tomNewTaiLu

#### tomOEM

#### tomOgham

#### tomOriya

#### tomPC437

#### tomRunic

#### tomShiftJIS

#### tomSinhala

#### tomSylotinagr

#### tomSymbol

#### tomSyriac

#### tomTaiLe

#### tomTamil

#### tomTelugu

#### tomThaana

#### tomThai

#### tomTibetan

#### tomTurkish

#### tomUsymbol

#### tomVietnamese

#### tomYi

### `Options` [in]

Type: **long**

The preferred font options. The low-order word can be a combination of the following values.

#### tomIgnoreCurrentFont

#### tomMatchCharRep

#### tomMatchFontSignature

#### tomMatchAscii

#### tomGetHeightOnly

#### tomMatchMathFont

If the high-order word of *Options* is [tomUseTwips](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants), the font heights are given in twips.

### `curCharRep` [in]

Type: **long**

The index of the current character repertoire.

### `curFontSize` [in]

Type: **long**

The current font size.

### `pbstr` [out]

Type: **BSTR***

The name of the font.

### `pPitchAndFamily` [out]

Type: **long***

The font pitch and family.

### `pNewFontSize` [out]

Type: **long***

The new font size.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)