# tomConstants enumeration

## Description

Defines values that are used with the Text Object Model (TOM) API.

## Constants

### `tomFalse:0`

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that indicates false.

### `tomTrue:-1`

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that indicates true.

### `tomUndefined:-9999999`

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that indicates a no-input, no-change value that works with **long**, **float**, and [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) parameters. For strings, **tomUndefined** (or NINCH) is represented by the null string. For Set operations, using **tomUndefined** does not change the target property. For Get operations, **tomUndefined** means that the characters in the range have different values (it gives the grayed check box in property dialog boxes).

### `tomToggle:-9999998`

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that toggles the state of a property.

### `tomAutoColor:-9999997`

Allow the rich edit control to select the appropriate color.

### `tomDefault:-9999996`

Set to the document default format for objects that are attached to a range, or to the basic TOM engine default for objects that are not attached to a range.

### `tomSuspend:-9999995`

Suspend an operation.

### `tomResume:-9999994`

Resume an operation.

### `tomApplyNow:0`

Apply the current properties to the attached range.

### `tomApplyLater:1`

Allow setting property definitions, but don’t apply them to a range yet.

### `tomTrackParms:2`

Update the current font with the attached range properties.

### `tomCacheParms:3`

Don’t update the current font with the attached range properties.

### `tomApplyTmp:4`

Apply temporary formatting.

### `tomDisableSmartFont:8`

Do not apply smart fonts.

### `tomEnableSmartFont:9`

Do apply smart fonts.

### `tomUsePoints:10`

Use points for floating-point measurements.

### `tomUseTwips:11`

Use twips for floating-point measurements.

### `tomBackward:0xc0000001`

Move backward toward the start of a story.

### `tomForward:0x3fffffff`

Move foreward toward the end of a story.

### `tomMove:0`

Collapse the selection or range to an insertion point and then move the insertion point.

### `tomExtend:1`

Extend a selection or range by moving one of the endpoints.

### `tomNoSelection:0`

There is no selection and no insertion point.

### `tomSelectionIP:1`

The selection insertion point.

### `tomSelectionNormal:2`

The selection is a single, nondegenerate text range.

### `tomSelectionFrame:3`

A frame is selected.

### `tomSelectionColumn:4`

One or more table columns is selected.

### `tomSelectionRow:5`

 One or more table rows is selected.

### `tomSelectionBlock:6`

A block is selected.

### `tomSelectionInlineShape:7`

The selection is a picture.

### `tomSelectionShape:8`

A shape is selected.

### `tomSelStartActive:1`

The starting position of the selection is active.

### `tomSelAtEOL:2`

For degenerate selections, the ambiguous character position corresponding to both the beginning of a line and the end of the preceding line should have the caret displayed at the end of the preceding line.

### `tomSelOvertype:4`

Insert/overtype mode is set to overtype.

### `tomSelActive:8`

Selection is active.

### `tomSelReplace:16`

Typing and pasting replaces the selection.

### `tomEnd:0`

The end of a text range.

### `tomStart:32`

The start of range.

### `tomCollapseEnd:0`

Collapse to the end position of a range or selection.

### `tomCollapseStart:1`

Collapse to the start position of a range or selection.

### `tomClientCoord:256`

Use client coordinates instead of screen coordinates.

### `tomAllowOffClient:512`

Allow points outside of the client area.

### `tomTransform:1024`

Transform coordinates using a world transform (XFORM) supplied by the host application.

### `tomObjectArg:2048`

Get a point inside an inline object argument; for example, inside the numerator of a fraction.

### `tomAtEnd:4096`

The end of the specified unit.

### `tomNone:0`

No underlining.

### `tomSingle:1`

Single underline.

### `tomWords:2`

Underline words only.

### `tomDouble:3`

Double underline.

### `tomDotted:4`

Dotted underline.

### `tomDash:5`

Dash underline.

### `tomDashDot:6`

Dash dot underline.

### `tomDashDotDot:7`

Dash dot dot underline.

### `tomWave:8`

Wave underline.

### `tomThick:9`

Thick underline.

### `tomHair:10`

Hair underline.

### `tomDoubleWave:11`

Double wave underline.

### `tomHeavyWave:12`

Heavy wave underline.

### `tomLongDash:13`

Long dash underline.

### `tomThickDash:14`

Thick dash underline.

### `tomThickDashDot:15`

Thick dash dot underline.

### `tomThickDashDotDot:16`

Thick dash dot dot underline.

### `tomThickDotted:17`

Thick dotted underline.

### `tomThickLongDash:18`

Thick long dash underline.

### `tomLineSpaceSingle:0`

Single space. The line-spacing value is ignored.

### `tomLineSpace1pt5:1`

One-and-a-half line spacing. The line-spacing value is ignored.

### `tomLineSpaceDouble:2`

Double line spacing. The line-spacing value is ignored.

### `tomLineSpaceAtLeast:3`

The line-spacing value specifies the spacing from one line to the next. However, if the value is less than single spacing, text is single-spaced.

### `tomLineSpaceExactly:4`

The line-spacing value specifies the exact spacing from one line to the next, even if the value is less than single spacing.

### `tomLineSpaceMultiple:5`

The line-spacing value specifies the line spacing, in lines.

### `tomLineSpacePercent:6`

The line-spacing value specifies the line spacing by percent of line height.

### `tomAlignLeft:0`

Text aligns with the left margin.

### `tomAlignCenter:1`

Text is centered between the margins.

### `tomAlignRight:2`

Text aligns with the right margin.

### `tomAlignJustify:3`

Text starts at the left margin and, if the line extends beyond the right margin, all the spaces in the line are adjusted to be even.

### `tomAlignDecimal:3`

The decimal point is set at the tab position. This is useful for aligning a column of decimal numbers.

### `tomAlignBar:4`

A vertical bar is positioned at the tab position. Text is not affected. Alignment bars on nearby lines at the same position form a continuous vertical line.

### `tomDefaultTab:5`

Position at a default tab stop.

### `tomAlignInterWord:3`

Same as **tomAlignJustify**.

### `tomAlignNewspaper:4`

Same as **tomAlignInterLetter**, but uses East Asian metrics.

### `tomAlignInterLetter:5`

The first and last characters of each line (except the last line) are aligned to the left and right margins, and lines are filled by adding or subtracting the same amount from each character.

### `tomAlignScaled:6`

Same as **tomAlignInterLetter**, but uses East Asian metrics, and scales the spacing by the width of characters.

### `tomSpaces:0`

Use spaces to fill the spaces taken by a tab character.

### `tomDots:1`

Use dots to fill the spaces taken by a tab character.

### `tomDashes:2`

Use dashes to fill the spaces taken by a tab character.

### `tomLines:3`

Use solid lines to fill the spaces taken by a tab character.

### `tomThickLines:4`

Use thick solid lines to fill the spaces taken by a tab character.

### `tomEquals:5`

Use equal signs to fill the spaces taken by a tab character.

### `tomTabBack:-3`

The tab preceding the specified location.

### `tomTabNext:-2`

The next tab following the specified location.

### `tomTabHere:-1`

The tab at the specified location.

### `tomListNone:0`

Not a list paragraph.

### `tomListBullet:1`

List uses bullets (0x2022); other bullets are given by > 32.

### `tomListNumberAsArabic:2`

List is numbered with Arabic numerals (0, 1, 2, ...).

### `tomListNumberAsLCLetter:3`

List is ordered with lowercase letters (a, b, c, ...).

### `tomListNumberAsUCLetter:4`

List is ordered with uppercase Arabic letters (A, B, C, ...).

### `tomListNumberAsLCRoman:5`

List is ordered with lowercase Roman letters (i, ii, iii, ...).

### `tomListNumberAsUCRoman:6`

List is ordered with uppercase Roman letters (I, II, III, ...).

### `tomListNumberAsSequence:7`

The value returned by [ITextPara::GetListStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getliststart) is treated as the first code in a Unicode sequence.

### `tomListNumberedCircle:8`

List is ordered with Unicode circled numbers

![Unicode numbers in a circle.](https://learn.microsoft.com/windows/win32/api/tom/images/unicodecirclednumbers.png)

### `tomListNumberedBlackCircleWingding:9`

List is ordered with Wingdings black circled digits

![Circled black digits.](https://learn.microsoft.com/windows/win32/api/tom/images/wingdingblackcircleddigits.png)

### `tomListNumberedWhiteCircleWingding:10`

List is ordered with Wingdings white circled digits:

![White digits in a black circle.](https://learn.microsoft.com/windows/win32/api/tom/images/wingdingwhitecircleddigits.png)

### `tomListNumberedArabicWide:11`

Full-width ASCII (０, １, ２, ３, …).

### `tomListNumberedChS:12`

Chinese with 十 only in items 10 through 99 (一, 二, 三, 四…).

### `tomListNumberedChT:13`

Chinese with 十 only in items 10 through 19.

### `tomListNumberedJpnChS:14`

Chinese with a full-width period, no 十.

### `tomListNumberedJpnKor:15`

Chinese with no 十.

### `tomListNumberedArabic1:16`

Arabic alphabetic ( أ ,ب ,ت ,ث ,…).

### `tomListNumberedArabic2:17`

Arabic abjadi ( أ ,ب ,ج ,د ,…).

### `tomListNumberedHebrew:18`

Hebrew alphabet (א, ב, ג, ד, …).

### `tomListNumberedThaiAlpha:19`

Thai alphabetic (ก, ข,ค, ง, …).

### `tomListNumberedThaiNum:20`

Thai numbers (๑, ๒,๓, ๔…).

### `tomListNumberedHindiAlpha:21`

Hindi vowels (अ, आ, इ, ई, …).

### `tomListNumberedHindiAlpha1:22`

Hindi consonants (क, ख, ग, घ, …).

### `tomListNumberedHindiNum:23`

Hindi numbers (१, २, ३, ४, …).

### `tomListParentheses:0x10000`

Encloses the number in parentheses, as in: (1).

### `tomListPeriod:0x20000`

Follows the number with a period.

### `tomListPlain:0x30000`

Uses the number alone.

### `tomListNoNumber:0x40000`

Uses no numbers.

### `tomListMinus:0x80000`

Follows the number with a hyphen (-).

### `tomIgnoreNumberStyle:0x1000000`

Suppress the numbering style for list items.

### `tomParaStyleNormal:-1`

The normal paragraph style.

### `tomParaStyleHeading1:-2`

The style for level 1 paragraph headings.

### `tomParaStyleHeading2:-3`

The style for level 2 paragraph headings.

### `tomParaStyleHeading3:-4`

The style for level 3 paragraph headings.

### `tomParaStyleHeading4:-5`

The style for level 4 paragraph headings.

### `tomParaStyleHeading5:-6`

The style for level 5 paragraph headings.

### `tomParaStyleHeading6:-7`

The style for level 6 paragraph headings.

### `tomParaStyleHeading7:-8`

The style for level 7 paragraph headings.

### `tomParaStyleHeading8:-9`

The style for level 8 paragraph headings.

### `tomParaStyleHeading9:-10`

The style for level 9 paragraph headings.

### `tomCharacter:1`

The unit is a single character.

### `tomWord:2`

The unit is a word.

### `tomSentence:3`

The unit is a sentence.

### `tomParagraph:4`

The unit is a paragraph.

### `tomLine:5`

The unit is a line.

### `tomStory:6`

The unit is a story; that is, a contiguous range of text that represent a part of a document, such as the main text of the document, headers and footers, footnotes, annotations, and so on.

### `tomScreen:7`

The unit is a screenful.

### `tomSection:8`

The unit is a section.

### `tomTableColumn:9`

The unit is a table column.

### `tomColumn:9`

The unit is a text column.

### `tomRow:0xc`

The unit is a table row

### `tomWindow:11`

The unit is a window.

### `tomCell:12`

The unit is a spreadsheet cell.

### `tomCharFormat:13`

The unit is a run of constant character formatting.

### `tomParaFormat:14`

The unit is a run of constant paragraph formatting.

### `tomTable:15`

The unit is a table.

### `tomObject:16`

The unit is an embedded object.

### `tomPage:17`

The unit is a page.

### `tomHardParagraph:18`

The unit is a hard paragraph.

### `tomCluster:19`

The unit is a cluster of characters.

### `tomInlineObject:20`

The unit is an inline object.

### `tomInlineObjectArg:21`

The unit is an inline object argument.

### `tomLeafLine:22`

The unit is a leaf-level line.

### `tomLayoutColumn:23`

A layout column.

### `tomProcessId:0x40000001`

The identifier of the current process.

### `tomMatchWord:2`

Match on whole words when doing a text search.

### `tomMatchCase:4`

A case-sensitive a text search.

### `tomMatchPattern:8`

Match regular expressions when doing a text search.

### `tomUnknownStory:0`

No special type.

### `tomMainTextStory:1`

The main story always exists for a rich edit control.

### `tomFootnotesStory:2`

The story used for footnotes.

### `tomEndnotesStory:3`

The story used for endnotes.

### `tomCommentsStory:4`

The story used for comments.

### `tomTextFrameStory:5`

The story used for a text box.

### `tomEvenPagesHeaderStory:6`

The story containing headers for even pages.

### `tomPrimaryHeaderStory:7`

The story containing headers for odd pages.

### `tomEvenPagesFooterStory:8`

The story containing footers for even pages.

### `tomPrimaryFooterStory:9`

The story containing footers for odd pages.

### `tomFirstPageHeaderStory:10`

The story containing the header for the first page.

### `tomFirstPageFooterStory:11`

The story containing the footer for the first page.

### `tomScratchStory:127`

The scratch story.

### `tomFindStory:128`

The story used for a Find dialog.

### `tomReplaceStory:129`

The story used for a Replace dialog.

### `tomStoryInactive:0`

Story is inactive.

### `tomStoryActiveDisplay:1`

Story has display, but no UI.

### `tomStoryActiveUI:2`

Story is UI active; that is, it receives keyboard and mouse input.

### `tomStoryActiveDisplayUI:3`

Story has display and UI activity.

### `tomNoAnimation:0`

Do not apply text animation.

### `tomLasVegasLights:1`

Text is bordered by marquee lights that blink between the colors red, yellow, green, and blue.

### `tomBlinkingBackground:2`

Text has a black background that blinks on and off.

### `tomSparkleText:3`

Text is overlaid with multicolored stars that blink on and off at regular intervals

### `tomMarchingBlackAnts:4`

Text is surrounded by a black dashed-line border. The border is animated so that the individual dashes appear to move clockwise around the text.

### `tomMarchingRedAnts:5`

Text is surrounded by a red dashed-line border that is animated to appear to move clockwise around the text.

### `tomShimmer:6`

Text is alternately blurred and unblurred at regular intervals, to give the appearance of shimmering.

### `tomWipeDown:7`

Text appears gradually from the top down.

### `tomWipeRight:8`

Text appears gradually from the bottom up.

### `tomAnimationMax:8`

Defines the maximum animation flag value.

### `tomLowerCase:0`

Set text to lowercase.

### `tomUpperCase:1`

Set text to uppercase.

### `tomTitleCase:2`

Capitalize the first letter of each word.

### `tomSentenceCase:4`

Capitalize the first letter of each sentence.

### `tomToggleCase:5`

Toggle the case of each letter.

### `tomReadOnly:0x100`

Read only.

### `tomShareDenyRead:0x200`

Other programs cannot read.

### `tomShareDenyWrite:0x400`

Other programs cannot write.

### `tomPasteFile:0x1000`

Replace the selection with a file.

### `tomCreateNew:0x10`

Create a new file. Fail if the file already exists.

### `tomCreateAlways:0x20`

Create a new file. Destroy the existing file if it exists.

### `tomOpenExisting:0x30`

Open an existing file. Fail if the file does not exist.

### `tomOpenAlways:0x40`

Open an existing file. Create a new file if the file does not exist.

### `tomTruncateExisting:0x50`

Open an existing file, but truncate it to zero length.

### `tomRTF:0x1`

Open as RTF.

### `tomText:0x2`

Open as text ANSI or Unicode.

### `tomHTML:0x3`

Open as HTML.

### `tomWordDocument:0x4`

Open as Word document.

### `tomBold:0x80000001`

Boldface.

### `tomItalic:0x80000002`

Italic.

### `tomUnderline:0x80000004`

Underline.

### `tomStrikeout:0x80000008`

Strikeout.

### `tomProtected:0x80000010`

Protected.

### `tomLink:0x80000020`

Hyperlink.

### `tomSmallCaps:0x80000040`

Small caps.

### `tomAllCaps:0x80000080`

All caps.

### `tomHidden:0x80000100`

Hidden.

### `tomOutline:0x80000200`

Outline.

### `tomShadow:0x80000400`

Shadow.

### `tomEmboss:0x80000800`

Emboss.

### `tomImprint:0x80001000`

Imprint.

### `tomDisabled:0x80002000`

Disabled.

### `tomRevised:0x80004000`

Revised.

### `tomSubscriptCF:0x80010000`

Subscript character format.

### `tomSuperscriptCF:0x80020000`

Superscript character format.

### `tomFontBound:0x80100000`

Font bound (uses font binding).

### `tomLinkProtected:0x80800000`

The link is protected (friendly name link).

### `tomInlineObjectStart:0x81000000`

The start delimiter of an inline object.

### `tomExtendedChar:0x82000000`

The characters are less common members of a script. A font that supports a script should check if it has glyphs for such characters.

### `tomAutoBackColor:0x84000000`

Use system back color.

### `tomMathZoneNoBuildUp:0x88000000`

Don't build up operator.

### `tomMathZone:0x90000000`

Math zone.

### `tomMathZoneOrdinary:0xa0000000`

Math zone ordinary text.

### `tomAutoTextColor:0xc0000000`

Use system text color.

### `tomMathZoneDisplay:0x40000`

Display math zone.

### `tomParaEffectRTL:0x1`

Right-to-left paragraph

### `tomParaEffectKeep:0x2`

Keep the paragraph together.

### `tomParaEffectKeepNext:0x4`

Keep with next the paragraph.

### `tomParaEffectPageBreakBefore:0x8`

Put a page break before this paragraph.

### `tomParaEffectNoLineNumber:0x10`

No line number for this paragraph.

### `tomParaEffectNoWidowControl:0x20`

No widow control.

### `tomParaEffectDoNotHyphen:0x40`

Don't hyphenate this paragraph.

### `tomParaEffectSideBySide:0x80`

Side by side.

### `tomParaEffectCollapsed:0x100`

 Heading contents are collapsed (in outline view).

### `tomParaEffectOutlineLevel:0x200`

Outline view nested level.

### `tomParaEffectBox:0x400`

Paragraph has boxed effect (is not displayed).

### `tomParaEffectTableRowDelimiter:0x1000`

At or inside table delimiter.

### `tomParaEffectTable:0x4000`

Inside or at the start of a table.

### `tomModWidthPairs:0x1`

Use East Asian character-pair-width modification.

### `tomModWidthSpace:0x2`

Use East Asian space-width modification.

### `tomAutoSpaceAlpha:0x4`

Use East Asian auto spacing between alphabetics.

### `tomAutoSpaceNumeric:0x8`

Use East Asian auto spacing for digits.

### `tomAutoSpaceParens:0x10`

Use East Asian automatic spacing for parentheses or brackets.

### `tomEmbeddedFont:0x20`

Embedded font (CLIP_EMBEDDED).

### `tomDoublestrike:0x40`

Double strikeout.

### `tomOverlapping:0x80`

Run has overlapping text.

### `tomNormalCaret:0`

Normal caret.

### `tomKoreanBlockCaret:0x1`

The Korean block caret.

### `tomNullCaret:0x2`

NULL caret (caret suppressed).

### `tomIncludeInset:0x1`

Add left/top insets to the client rectangle, and subtract right/bottom insets from the client rectangle.

### `tomUnicodeBiDi:0x1`

Use the Unicode bidirectional (bidi) algorithm.

### `tomMathCFCheck:0x4`

Check math-zone character formatting.

### `tomUnlink:0x8`

Don't include text as part of a hyperlink.

### `tomUnhide:0x10`

Don't insert as hidden text.

### `tomCheckTextLimit:0x20`

Obey the current text limit instead of increasing the text to fit.

### `tomIgnoreCurrentFont:0`

Ignore the font that is active at a particular character position.

### `tomMatchCharRep:0x1`

Match the current character repertoire.

### `tomMatchFontSignature:0x2`

Match the current font signature.

### `tomMatchAscii:0x4`

Use the current font if its character repertoire is **tomAnsi**.

### `tomGetHeightOnly:0x8`

Gets the height.

### `tomMatchMathFont:0x10`

Match a math font.

### `tomCharset:0x80000000`

Set the character repertoire based on the specified character set.

### `tomCharRepFromLcid:0x40000000`

Set the character repertoire based on the specified LCID.

### `tomAnsi:0`

Latin 1

### `tomEastEurope:1`

From Latin 1 and 2

### `tomCyrillic:2`

Cyrillic

### `tomGreek:3`

Greek

### `tomTurkish:4`

Turkish (Latin 1 + dotless i, ...)

### `tomHebrew:5`

Hebrew

### `tomArabic:6`

Arabic

### `tomBaltic:7`

From Latin 1 and 2

### `tomVietnamese:8`

Latin 1 with some combining marks

### `tomDefaultCharRep:9`

Default character repertoire

### `tomSymbol:10`

Symbol character set (not Unicode)

### `tomThai:11`

Thai

### `tomShiftJIS:12`

Japanese

### `tomGB2312:13`

Simplified Chinese

### `tomHangul:14`

Hangul

### `tomBIG5:15`

Traditional Chinese

### `tomPC437:16`

PC437 character set (DOS)

### `tomOEM:17`

OEM character set (original PC)

### `tomMac:18`

Main Macintosh character repertoire

### `tomArmenian:19`

Armenian

### `tomSyriac:20`

Syriac

### `tomThaana:21`

Thaana

### `tomDevanagari:22`

Devanagari

### `tomBengali:23`

Bangla (formerly Bengali)

### `tomGurmukhi:24`

Gurmukhi

### `tomGujarati:25`

Gujarati

### `tomOriya:26`

Odia (formerly Oriya)

### `tomTamil:27`

Tamil

### `tomTelugu:28`

Telugu

### `tomKannada:29`

Kannada

### `tomMalayalam:30`

Malayalam

### `tomSinhala:31`

Sinhala

### `tomLao:32`

Lao

### `tomTibetan:33`

Tibetan

### `tomMyanmar:34`

Myanmar

### `tomGeorgian:35`

Georgian

### `tomJamo:36`

Jamo

### `tomEthiopic:37`

Ethiopic

### `tomCherokee:38`

Cherokee

### `tomAboriginal:39`

Aboriginal

### `tomOgham:40`

Ogham

### `tomRunic:41`

Runic

### `tomKhmer:42`

Khmer

### `tomMongolian:43`

Mongolian

### `tomBraille:44`

Braille

### `tomYi:45`

Yi

### `tomLimbu:46`

Limbu

### `tomTaiLe:47`

TaiLe

### `tomNewTaiLue:48`

TaiLue

### `tomSylotiNagri:49`

Syloti Nagri

### `tomKharoshthi:50`

Kharoshthi

### `tomKayahli:51`

Kayah Li

### `tomUsymbol:52`

Unicode symbol

### `tomEmoji:53`

Emoji

### `tomGlagolitic:54`

Glagolitic

### `tomLisu:55`

Lisu

### `tomVai:56`

Vai

### `tomNKo:57`

N'Ko

### `tomOsmanya:58`

Osmanya

### `tomPhagsPa:59`

Phags-pa

### `tomGothic:60`

Gothic

### `tomDeseret:61`

Deseret

### `tomTifinagh:62`

Tifinagh

### `tomCharRepMax:63`

The maximum character repertoire flag value.

### `tomRE10Mode:0x1`

Use Microsoft Rich Edit 1.0 mode.

### `tomUseAtFont:0x2`

Use a font with a name that starts with @, for CJK vertical text. When rendered vertically, the characters in such a font are rotated 90 degrees so that they look upright instead of sideways.

### `tomTextFlowMask:0xc`

Mask for the following four text orientations.

### `tomTextFlowES:0`

Ordinary left-to-right horizontal text.

### `tomTextFlowSW:0x4`

Ordinary East Asian vertical text.

### `tomTextFlowWN:0x8`

Alternative orientation.

### `tomTextFlowNE:0xc`

Alternative orientation.

### `tomNoIME:0x80000`

Disables the IME operation (see [ES_NOIME](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-styles)).

### `tomSelfIME:0x40000`

Directs the rich edit control to allow the application to handle all IME operations (see [ES_SELFIME](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-styles)).

### `tomNoUpScroll:0x10000`

Horizontal scrolling is disabled.

### `tomNoVpScroll:0x40000`

Vertical scrolling is disabled.

### `tomNoLink:0`

Not a link.

### `tomClientLink:1`

The URL only; that is, no friendly name.

### `tomFriendlyLinkName:2`

The name of friendly name link.

### `tomFriendlyLinkAddress:3`

The URL of a friendly name link.

### `tomAutoLinkURL:4`

The URL of an automatic link.

### `tomAutoLinkEmail:5`

An automatic link to an email address.

### `tomAutoLinkPhone:6`

An automatic link to a phone number.

### `tomAutoLinkPath:7`

An automatic link to a storage location.

### `tomCompressNone:0`

No compression.

### `tomCompressPunctuation:1`

Compress punctuation.

### `tomCompressPunctuationAndKana:2`

Compress punctuation and kana.

### `tomCompressMax:2`

The maximum compression flag value.

### `tomUnderlinePositionAuto:0`

Automatically set the underline position.

### `tomUnderlinePositionBelow:1`

Render underline below text.

### `tomUnderlinePositionAbove:2`

Render underline above text.

### `tomUnderlinePositionMax:2`

The maximum underline position flag value.

### `tomFontAlignmentAuto:0`

For horizontal layout, align CJK characters on the baseline. For vertical layout, center align CJK characters.

### `tomFontAlignmentTop:1`

For horizontal layout, top align CJK characters. For vertical layout, right align CJK characters.

### `tomFontAlignmentBaseline:2`

For horizontal or vertical layout, align CJK characters on the baseline.

### `tomFontAlignmentBottom:3`

For horizontal layout, bottom align CJK characters. For vertical layout, left align CJK characters.

### `tomFontAlignmentCenter:4`

For horizontal layout, center CJK characters vertically. For vertical layout, center align CJK characters horizontally.

### `tomFontAlignmentMax:4`

The maximum font alignment flag value.

### `tomRubyBelow:0x80`

### `tomRubyAlignCenter:0`

### `tomRubyAlign010:1`

### `tomRubyAlign121:2`

### `tomRubyAlignLeft:3`

### `tomRubyAlignRight:4`

### `tomLimitsDefault:0`

Limit locations use document default.

### `tomLimitsUnderOver:1`

Limits are placed under and over the operator.

### `tomLimitsSubSup:2`

Limits are operator subscript and superscript.

### `tomUpperLimitAsSuperScript:3`

The upper limit is a superscript.

### `tomLimitsOpposite:4`

Switch between **tomLimitsSubSup** and **tomLimitsUnderOver**.

### `tomShowLLimPlaceHldr:8`

Show empty lower limit placeholder.

### `tomShowULimPlaceHldr:16`

Show empty upper limit placeholder.

### `tomDontGrowWithContent:64`

Don't grow the *n*-ary operator with the argument.

### `tomGrowWithContent:128`

Grow the *n*-ary operator with the argument.

### `tomSubSupAlign:1`

Align subscript under superscript.

### `tomLimitAlignMask:3`

Mask for **tomLimitAlignCenter**, **tomLimitAlignLeft**, and **tomLimitAlignRight.**

### `tomLimitAlignCenter:0`

Center limit under base.

### `tomLimitAlignLeft:1`

Align left ends of limit and base.

### `tomLimitAlignRight:2`

Align right ends of limit and base.

### `tomShowDegPlaceHldr:8`

Show empty radical degree placeholder.

### `tomAlignDefault:0`

Center brackets at baseline.

### `tomAlignMatchAscentDescent:2`

Use brackets that match the argument ascent and descent.

### `tomMathVariant:0x20`

Bits 7, 6 can have TeX variant enumeration values:

### `tomStyleDefault:0`

The math handler determines the style.

### `tomStyleScriptScriptCramped:1`

The 2nd and higher level subscript superscript size, cramped.

### `tomStyleScriptScript:2`

The 2nd and higher level subscript superscript size.

### `tomStyleScriptCramped:3`

The 1st level subscript superscript size, cramped.

### `tomStyleScript:4`

The 1st level subscript superscript size.

### `tomStyleTextCramped:5`

Text size cramped, for example, inside a square root.

### `tomStyleText:6`

The standard inline text size.

### `tomStyleDisplayCramped:7`

Display style cramped.

### `tomStyleDisplay:8`

Display style.

### `tomMathRelSize:0x40`

Indicates one of these is active: **tomDecDecSize**, **tomDecSize**, **tomIncSize**, **tomIncIncSize**. Note that the maximum size is **tomStyleText** size, and the minimum size is **tomStyleScriptScript** size.

### `tomDecDecSize:0xfe`

Two sizes smaller than the default.

### `tomDecSize:0xff`

One size smaller than the default.

### `tomIncSize`

One size bigger than the default.

### `tomIncIncSize`

Two sizes bigger than the default.

### `tomGravityUI:0`

Use selection user interface rules.

### `tomGravityBack:1`

Both ends have backward gravity.

### `tomGravityFore:2`

Both ends have forward gravity.

### `tomGravityIn:3`

Inward gravity; that is, the start is forward, and the end is backward.

### `tomGravityOut:4`

Outward gravity; that is, the start is backward, and the end is forward.

### `tomGravityBackward:0x20000000`

### `tomGravityForward:0x40000000`

### `tomAdjustCRLF:1`

Adjust CR/LFs at the start.

### `tomUseCRLF:2`

Use CR/LF in place of a carriage return or a line feed.

### `tomTextize:4`

Copy up to 0xFFFC (OLE object).

### `tomAllowFinalEOP:8`

Allow a final end-of-paragraph (EOP) marker.

### `tomFoldMathAlpha:16`

Fold math alphanumerics to ASCII/Greek.

### `tomNoHidden:32`

Don't include hidden text.

### `tomIncludeNumbering:64`

Include list numbers.

### `tomTranslateTableCell:128`

Replace table row delimiter characters with spaces.

### `tomNoMathZoneBrackets:0x100`

Don't include math zone brackets.

### `tomConvertMathChar:0x200`

Convert to or from math italic and/or math bold according to the status of italic and bold retrieved by the [ITextFont2::GetEffects](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-geteffects) method.

### `tomNoUCGreekItalic:0x400`

Don’t use math italics for upper-case Greek letters. This value is used with
**tomConvertMathChar**.

### `tomAllowMathBold:0x800`

Allow math bold. This value is used with
**tomConvertMathChar**.

### `tomLanguageTag:0x1000`

Get the BCP-47 language tag for this range.

### `tomConvertRTF:0x2000`

Get text in RTF.

### `tomApplyRtfDocProps:0x4000`

Apply RTF document default properties.

### `tomPhantomShow:1`

Display the phantom object's argument.

### `tomPhantomZeroWidth:2`

The phantom object has zero width.

### `tomPhantomZeroAscent:4`

The phantom object has zero ascent.

### `tomPhantomZeroDescent:8`

The phantom object has zero descent.

### `tomPhantomTransparent:16`

Space the phantom object as if only the argument is present.

### `tomPhantomASmash`

Ascent smash.

### `tomPhantomDSmash`

Descent smash.

### `tomPhantomHSmash`

Horizontal smash.

### `tomPhantomSmash`

Full smash.

### `tomPhantomHorz`

Horizontal phantom.

### `tomPhantomVert`

Vertical phantom.

### `tomBoxHideTop:1`

Hide top border.

### `tomBoxHideBottom:2`

Hide bottom border.

### `tomBoxHideLeft:4`

Hide left border.

### `tomBoxHideRight:8`

Hide right border.

### `tomBoxStrikeH:16`

Display horizontal strikethrough.

### `tomBoxStrikeV:32`

Display vertical strikethrough.

### `tomBoxStrikeTLBR:64`

Display diagonal strikethrough from the top left to the lower right.

### `tomBoxStrikeBLTR:128`

Display diagonal strikethrough from the lower left to the top right.

### `tomBoxAlignCenter:1`

Vertically align with center on baseline.

### `tomSpaceMask:0x1c`

Mask for **tomSpaceDefault**, **tomSpaceUnary**, **tomSpaceBinary**, **tomSpaceRelational**, **tomSpaceSkip**, **tomSpaceOrd**, and **tomSpaceDifferential.**

### `tomSpaceDefault:0`

Default spacing

### `tomSpaceUnary:4`

Space the object as if it were a unary operator.

### `tomSpaceBinary:8`

Space the object as if it were a binary operator.

### `tomSpaceRelational:12`

Space the object as if it were a relational operator.

### `tomSpaceSkip:16`

Space the object as if it were a unary operator.

### `tomSpaceOrd:20`

Space the object as if it were an ordinal operator.

### `tomSpaceDifferential:24`

Space the object as if it were a differential operator.

### `tomSizeText:32`

Treat as text size.

### `tomSizeScript:64`

Treat as script size (approximately 73% of text size).

### `tomSizeScriptScript:96`

Treat as subscript size (approximately 60% of text size).

### `tomNoBreak:128`

Do not break arguments across a line.

### `tomTransparentForPositioning:256`

Position as if only the argument appears.

### `tomTransparentForSpacing:512`

Space according to argument properties.

### `tomStretchCharBelow:0`

Stretch character below base.

### `tomStretchCharAbove:1`

Stretch character above base.

### `tomStretchBaseBelow:2`

Stretch base below character.

### `tomStretchBaseAbove:3`

Stretch base above character.

### `tomMatrixAlignMask:3`

Mask for **tomMatrixAlignCenter**, **tomMatrixAlignTopRow**, and **tomMatrixAlignBottomRow.**

### `tomMatrixAlignCenter:0`

Align the matrix center on baseline.

### `tomMatrixAlignTopRow:1`

Align the matrix top row on the baseline.

### `tomMatrixAlignBottomRow:3`

Align the matrix bottom row on the baseline.

### `tomShowMatPlaceHldr:8`

Show empty element placeholder (a dotted box).

### `tomEqArrayLayoutWidth:1`

Expand the right size to the layout width (for equation number)

### `tomEqArrayAlignMask:0xc`

Mask for **tomEqArrayAlignCenter**, **tomEqArrayAlignTopRow**, and **tomEqArrayBottomRow.**

### `tomEqArrayAlignCenter:0`

Align the center of the equation array on the baseline.

### `tomEqArrayAlignTopRow:4`

Align the top of equations on the baseline.

Align the top row of the equation on the baseline.

### `tomEqArrayAlignBottomRow:0xc`

Align the bottom row of the equation on the baseline.

### `tomMathManualBreakMask:0x7f`

Mask for **tomMathBreakLeft**, **tomMathBreakCenter**, and **tomMathBreakRight.**

### `tomMathBreakLeft:0x7d`

Align text following a manual break to the left.

### `tomMathBreakCenter:0x7e`

Center text following a manual break.

### `tomMathBreakRight:0x7f`

Align text following a manual break to the right.

### `tomMathEqAlign:0x80`

Math equation alignment.

### `tomMathArgShadingStart:0x251`

Start shading math arguments.

### `tomMathArgShadingEnd:0x252`

End shading math arguments.

### `tomMathObjShadingStart:0x253`

Start shading math objects.

### `tomMathObjShadingEnd:0x254`

End shading math objects.

### `tomFunctionTypeNone:0`

Not in the function list.

### `tomFunctionTypeTakesArg:1`

An ordinary math function that takes arguments.

### `tomFunctionTypeTakesLim:2`

Use the lower limit for _, and so on.

### `tomFunctionTypeTakesLim2:3`

Turn the preceding FA into an NBSP.

### `tomFunctionTypeIsLim:4`

A "lim" function.

### `tomMathParaAlignDefault:0`

The default alignment for math paragraphs.

### `tomMathParaAlignCenterGroup:1`

Center math paragraphs as a group.

### `tomMathParaAlignCenter:2`

Center math paragraphs.

### `tomMathParaAlignLeft:3`

Left-align math paragraphs.

### `tomMathParaAlignRight:4`

Right-align math paragraphs.

### `tomMathDispAlignMask:3`

Mask for **tomMathDispAlignCenterGroup**, **tomMathDispAlignCenter**, **tomMathDispAlignLeft**, **tomMathDispAlignRight**, **tomMathDispIntUnderOver**, and **tomMathDispNaryGrow**.

### `tomMathDispAlignCenterGroup:0`

Center a math paragraph as a group.

### `tomMathDispAlignCenter:1`

Center all equations in a math paragraph.

### `tomMathDispAlignLeft:2`

Left justify all equations in a math paragraph.

### `tomMathDispAlignRight:3`

Right justify all equations in a math paragraph.

### `tomMathDispIntUnderOver:4`

Display-mode integral limits location.

### `tomMathDispFracTeX:8`

Indicates whether to use display-mode nested fraction script size.

### `tomMathDispNaryGrow:0x10`

Indicates whether to use math-paragraph n-ary grow.

### `tomMathDocEmptyArgMask:0x60`

Empty arguments display mask.

### `tomMathDocEmptyArgAuto:0`

Dotted square, if necessary.

### `tomMathDocEmptyArgAlways:0x20`

Dotted square, always.

### `tomMathDocEmptyArgNever:0x40`

Nothing.

### `tomMathDocSbSpOpUnchanged:0x80`

Do not display the underscore (_) as subscripted, or the caret (^) as superscripted.

### `tomMathDocDiffMask:0x300`

Style mask for the **tomMathDocDiffUpright**, **tomMathDocDiffItalic**, **tomMathDocDiffOpenItalic**  options.

### `tomMathDocDiffDefault:0`

Use default glyphs for math differentials.

### `tomMathDocDiffUpright:0x100`

Use upright glyphs for math differentials.

### `tomMathDocDiffItalic:0x200`

Use italic glyphs for math differentials.

### `tomMathDocDiffOpenItalic:0x300`

No glyph change.

### `tomMathDispNarySubSup:0x400`

Math-paragraph non-integral n-ary limits location.

### `tomMathDispDef:0x800`

Math-paragraph spacing defaults. Use math paragraph offsets instead of regular paragraph offsets.

### `tomMathEnableRtl:0x1000`

Enable right-to-left (RTL) math zones in RTL paragraphs.

### `tomMathBrkBinMask:0x30000`

Equation line break mask.

### `tomMathBrkBinBefore:0`

Break before binary/relational operator.

### `tomMathBrkBinAfter:0x10000`

Break after binary/relational operator.

### `tomMathBrkBinDup:0x20000`

Duplicate binary/relational before/after.

### `tomMathBrkBinSubMask:0xc0000`

Duplicate mask for minus operator.

### `tomMathBrkBinSubMM:0`

-- (minus on both lines).

### `tomMathBrkBinSubPM:0x40000`

+ -

### `tomMathBrkBinSubMP:0x80000`

- +

### `tomSelRange:0x255`

Set the selection character position and character count to range values.

### `tomHstring:0x254`

Use a string handle (**HSTRING**) instead of a binary string (**BSTR**).

### `tomFontPropTeXStyle:0x33c`

Gets the TeX style of the font.

### `tomFontPropAlign:0x33d`

Use **tomFontPropAlign** to get the **Align** property of an operator in a math zone. Here are how the values are assigned:

* Value 0 implies no special alignment.
* Values 1 through 127 align the operator with the (n – 1)st operator on the first line of an equation.
* Value 128 identifies operators to be vertically aligned with respect to one another ("Align at =").
* Other values are illegal.

### `tomFontStretch:0x33e`

The type of font stretching. It can have one of the following values.

**tomFontStretchDefault**
**tomFontStretchUltraCondensed**
**tomFontStretchExtraCondensed**
**tomFontStretchCondensed**
**tomFontStretchNormal**
**tomFontStretchSemiExpanded**
**tomFontStretchExpanded**
**tomFontStretchExtraExpanded**
**tomFontStretchUltraExpanded**

### `tomFontStyle:0x33f`

The font style. It can have one of the following values.

* **tomFontStyleUpright**
* **tomFontStyleItalic**
* **tomFontStyleOblique**

### `tomFontStyleUpright:0`

Represents the normal upright font style.

### `tomFontStyleOblique:1`

Represents an oblique font style.

### `tomFontStyleItalic:2`

Represents an italic font style.

### `tomFontStretchDefault:0`

No defined font stretch.

### `tomFontStretchUltraCondensed:1`

An ultra-condensed font stretch (50% of normal).

### `tomFontStretchExtraCondensed:2`

An extra-condensed font stretch (62.5% of normal).

### `tomFontStretchCondensed:3`

A condensed font stretch (75% of normal).

### `tomFontStretchSemiCondensed:4`

A semi-condensed font stretch (87.5% of normal).

### `tomFontStretchNormal:5`

The normal font stretch that all other font stretch values relate to (100%).

### `tomFontStretchSemiExpanded:6`

A semi-expanded font stretch (112.5% of normal).

### `tomFontStretchExpanded:7`

An expanded font stretch (125% of normal).

### `tomFontStretchExtraExpanded:8`

An extra-expanded font stretch (150% of normal).

### `tomFontStretchUltraExpanded:9`

An ultra-expanded font stretch (200% of normal).

### `tomFontWeightDefault:0`

The default font weight.

### `tomFontWeightThin:100`

Thin font weight.

### `tomFontWeightExtraLight:200`

Extra light font weight.

### `tomFontWeightLight:300`

Light font weight.

### `tomFontWeightNormal:400`

Normal font weight.

### `tomFontWeightRegular:400`

Same as **tomFontWeightNormal**.

### `tomFontWeightMedium:500`

Medium font weight.

### `tomFontWeightSemiBold:600`

Semi bold font weight.

### `tomFontWeightBold:700`

Bold font weight.

### `tomFontWeightExtraBold:800`

Extra bold font weight.

### `tomFontWeightBlack:900`

Heavy font weight.

### `tomFontWeightHeavy:900`

Same as **tomFontWeightBlack**.

### `tomFontWeightExtraBlack:950`

Extra heavy font weight.

### `tomParaPropMathAlign:0x437`

Alignment properties for a math paragraph.

### `tomDocMathBuild:0x80`

Used with the [ITextDocument2::SetProperty](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-setproperty) method to set any combination of **tomMathAutoCorrect**, **tomTeX**, or **tomMathAlphabetics**.

### `tomMathLMargin:0x81`

Left margin for display math.

### `tomMathRMargin:0x82`

Right margin for display math.

### `tomMathWrapIndent:0x83`

Equation wrap indent for display math.

### `tomMathWrapRight:0x84`

Equation right wrap indent for display math (in a left-to-right (LTR) math zone).

### `tomMathPostSpace:0x86`

Space after a display math equation.

### `tomMathPreSpace:0x85`

Space before a display math equation.

### `tomMathInterSpace:0x87`

Space between equations in math paragraphs.

### `tomMathIntraSpace:0x88`

Space between lines in a display math equation.

### `tomCanCopy:0x89`

Indicates whether data can be copied to the clipboard.

### `tomCanRedo:0x8a`

Indicates whether one or more redo operations exist.

### `tomCanUndo:0x8b`

Indicates whether one or more undo operations exist.

### `tomUndoLimit:0x8c`

The undo stack count limit.

### `tomDocAutoLink:0x8d`

A document automatic link.

### `tomEllipsisMode:0x8e`

The ellipsis mode.

### `tomEllipsisState:0x8f`

The ellipsis state.

### `tomEllipsisNone:0`

Ellipsis is disabled.

### `tomEllipsisEnd:1`

An ellipsis forces a break anywhere in the line.

### `tomEllipsisWord:3`

An ellipsis forces a break between words.

### `tomEllipsisPresent:1`

Ellipsis is present.

### `tomVTopCell:1`

The top cell in vertically merged cell set.

### `tomVLowCell:2`

Any cell except the top cell in a vertically merged cell set.

### `tomHStartCell:4`

Start a cell in a horizontally merged cell set.

### `tomHContCell:8`

Any cell except the start in a horizontally merged cell set.

### `tomRowUpdate:1`

Update the row to have the properties of the table row identified by the associated text range.

### `tomRowApplyDefault:0`

### `tomCellStructureChangeOnly:1`

Changes cell width(s) or cell count (for changing column widths and inserting/deleting columns without changing cell border properties, and so forth.)

### `tomRowHeightActual:0x80b`

The actual height of a table row.

#### - tomChemicalFormula

Use chemical formula conversions.

#### - tomHaveDelimiter

A delimiter follows insertion points (formula automatic buildup).

#### - tomMathAlignBreakCenter

Center text following a manual break.

#### - tomMathAlignBreakLeft

Align text following a manual break to the left.

#### - tomMathAlignBreakRight

Align text following a manual break to the right.

#### - tomMathAlphabetics

Use math alphabetics for English/Greek letters except for math function names.

#### - tomMathApplyTemplate

Apply an object template to a range.

#### - tomMathArabicAlphabetics

Use Arabic math alphabetics for variables.

#### - tomMathAutoComplete

Show a tooltip with options for math autocompletions.

#### - tomMathAutoCorrect

Internal math autocorrect standard math \ keywords.

#### - tomMathAutoCorrectExt

Invoke external autocorrect in manual build up.

#### - tomMathAutoCorrectOpPairs

Autocorrect operator pairs.

#### - tomMathBackspace

Handle the Backspace key inside a math object.

#### - tomMathBuildDown

Build down instead of up.

#### - tomMathBuildDownOutermost

Build down only outermost objects.

#### - tomMathBuildUpArgOrZone

Build up insertion points argument or zone.

#### - tomMathBuildUpRecurse

Enable recursive build up.

#### - tomMathChangeMask

Mask for specifying changes to make during math linearization (build down). It can be a combination of the following values.

[tomMathInsRowBefore](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathInsRowAfter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathInsColBefore](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathInsColAfter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathDeleteRow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathDeleteCol](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathDeleteArg](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathDeleteArg1](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathDeleteArg2](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathMakeFracLinear](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathMakeFracStacked](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathMakeFracSlashed](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathMakeLeftSubSup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathMakeSubSup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathBackspace](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathEnter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathShiftTab](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathTab](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathSubscript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMathSuperscript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

#### - tomMathCollapseSel

Collapse the selection after build up or build down.

#### - tomMathDeleteArg

Delete the argument at the start of the range.

#### - tomMathDeleteArg1

Delete argument 1 (0-based count).

#### - tomMathDeleteArg2

Delete argument 2 (0-based count).

#### - tomMathDeleteCol

Delete a column.

#### - tomMathDeleteRow

Delete a row.

#### - tomMathEnter

Handle the Enter key inside a math object.

#### - tomMathInsColAfter

Insert a column or separator after the current argument.

#### - tomMathInsColBefore

Insert a column or separator before the current argument.

#### - tomMathInsRowAfter

Insert a row below the insertion point.

#### - tomMathInsRowBefore

Insert a row above the insertion point.

#### - tomMathMakeFracLinear

Change to a linear fraction.

#### - tomMathMakeFracSlashed

Change to a slashed fraction.

#### - tomMathMakeFracStacked

Change to a stacked fraction.

#### - tomMathMakeLeftSubSup

Change from **tomSubSup** to **tomLeftSubSup**.

#### - tomMathMakeSubSup

Change **tomLeftSubSup** to **tomSubSup**.

#### - tomMathRemoveOutermost

Build down the outermost object without its characters.

#### - tomMathRichEdit

Handle minor differences between the rich edit control and Word.

#### - tomMathShiftTab

Handle the Shift+Tab key combination inside a math object.

#### - tomMathSingleChar

Single character typed for build up.

#### - tomMathSubscript

Handle the Ctrl+= key combination in a math zone.

#### - tomMathSuperscript

Handle the Ctrl+Shift+= key combination in a math zone.

#### - tomMathTab

Handle the Tab key inside a math object.

#### - tomNeedTermOp

A terminating operator is needed. Only used with a degenerate range for formula autobuildup.

#### - tomPlain

Build down for plain text.

#### - tomShowEmptyArgPlaceholders

Don't hide empty argument placeholders on build-up.

#### - tomSpecialChar

The character is treated as part of the current operand.

#### - tomTeX

Enables TeX syntax for build up/down operations. The **tomTeX** style can have the following values:

[tomStyleDefault](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomStyleScriptScriptCramped](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomStyleScriptScript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomStyleScriptCramped](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomStyleScript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomStyleTextCramped](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomStyleText](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomStyleDisplayCramped](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomStyleDisplay](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomDecDecSize](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomDecSize](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomIncSize](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

[tomIncIncSize](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

#### - tomUseOperandPrec

Use operand precedence.