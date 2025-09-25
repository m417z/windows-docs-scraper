# ITextPara::GetStyle

## Description

Retrieves the style handle to the paragraphs in the specified range.

## Parameters

### `pValue`

Type: **long***

The paragraph style handle. For more information, see the Remarks.

## Return value

Type: **HRESULT**

If **ITextPara::GetStyle** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

The Text Object Model (TOM) version 1.0 has no way to specify the meanings of user-defined style handles. They depend on other facilities of the text system implementing TOM. Negative style handles are reserved for built-in character and paragraph styles. Currently defined values are listed in the following table. For a description of the following styles, see the Microsoft Word documentation.

| Style | Value | Style | Value |
| --- | --- | --- | --- |
| StyleNormal | –1 | StyleTableofAuthorities | –45 |
| StyleHeading1 | –2 | StyleMacroText | –46 |
| StyleHeading2 | –3 | StyleTOAHeading | –47 |
| StyleHeading3 | –4 | StyleList | –48 |
| StyleHeading4 | –5 | StyleListBullet | –49 |
| StyleHeading5 | –6 | StyleListNumber | –50 |
| StyleHeading6 | –7 | StyleList2 | –51 |
| StyleHeading7 | –8 | StyleList3 | –52 |
| StyleHeading8 | –9 | StyleList4 | –53 |
| StyleHeading9 | –10 | StyleList5 | –54 |
| StyleIndex1 | –11 | StyleListBullet2 | –55 |
| StyleIndex2 | –12 | StyleListBullet3 | –56 |
| StyleIndex3 | –13 | StyleListBullet4 | –57 |
| StyleIndex4 | –14 | StyleListBullet5 | –58 |
| StyleIndex5 | –15 | StyleListNumber2 | –59 |
| StyleIndex6 | –16 | StyleListNumber3 | –60 |
| StyleIndex7 | –17 | StyleListNumber4 | –61 |
| StyleIndex8 | –18 | StyleListNumber5 | –62 |
| StyleIndex9 | –19 | StyleTitle | –63 |
| StyleTOC1 | –20 | StyleClosing | –64 |
| StyleTOC2 | –21 | StyleSignature | –65 |
| StyleTOC3 | –22 | StyleDefaultParagraphFont | –66 |
| StyleTOC4 | –23 | StyleBodyText | –67 |
| StyleTOC5 | –24 | StyleBodyTextIndent | –68 |
| StyleTOC6 | –25 | StyleListContinue | –69 |
| StyleTOC7 | –26 | StyleListContinue2 | –70 |
| StyleTOC8 | –27 | StyleListContinue3 | –71 |
| StyleTOC9 | –28 | StyleListContinue4 | –72 |
| StyleNormalIndent | –29 | StyleListContinue5 | –73 |
| StyleFootnoteText | –30 | StyleMessageHeader | –74 |
| StyleAnnotationText | –31 | StyleSubtitle | –75 |
| StyleHeader | –32 | StyleSalutation | –76 |
| StyleFooter | –33 | StyleDate | –77 |
| StyleIndexHeading | –34 | StyleBodyTextFirstIndent | –78 |
| StyleCaption | –35 | StyleBodyTextFirstIndent2 | –79 |
| StyleTableofFigures | –36 | StyleNoteHeading | –80 |
| StyleEnvelopeAddress | –37 | StyleBodyText2 | –81 |
| StyleEnvelopeReturn | –38 | StyleBodyText3 | –82 |
| StyleFootnoteReference | –39 | StyleBodyTextIndent2 | –83 |
| StyleAnnotationReference | –40 | StyleBodyTextIndent3 | –84 |
| StyleLineNumber | –41 | StyleBlockQuotation | –85 |
| StylePageNumber | –42 | StyleHyperlink | –86 |
| StyleEndnoteReference | –43 | StyleHyperlinkFollowed | –87 |
| StyleEndnoteText | –44 |  |  |

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetStyle](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setstyle)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)