/* ************************************************************************************* */
/* *    PhatWare WritePad SDK                                                          * */
/* *    Copyright (c) 2008-2015 PhatWare(r) Corp. All rights reserved.                 * */
/* ************************************************************************************* */

/* ************************************************************************************* *
 *
 * WritePad SDK Sample
 *
 * Unauthorized distribution of this code is prohibited. For more information
 * refer to the End User Software License Agreement provided with this
 * software.
 *
 * This source code is distributed and supported by PhatWare Corp.
 * http://www.phatware.com
 *
 * THIS SAMPLE CODE CAN BE USED  AS A REFERENCE AND, IN ITS BINARY FORM,
 * IN THE USER'S PROJECT WHICH IS INTEGRATED WITH THE WRITEPAD SDK.
 * ANY OTHER USE OF THIS CODE IS PROHIBITED.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL PHATWARE CORP.
 * BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT, SPECIAL, INCIDENTAL,
 * INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER,
 * INCLUDING WITHOUT LIMITATION, LOSS OF PROFIT, LOSS OF USE, SAVINGS
 * OR REVENUE, OR THE CLAIMS OF THIRD PARTIES, WHETHER OR NOT PHATWARE CORP.
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in EULA and in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is PhatWare Corp.
 * 1314 S. Grand Blvd. Ste. 2-175 Spokane, WA 99202
 *
 * ************************************************************************************* */

#import <UIKit/UIKit.h>
#import <UIKit/UITextChecker.h>

#import "RecognizerWrapper.h"

typedef enum
{
	WPLanguageUnknown = 0,
	WPLanguageEnglishUS = 1,
	WPLanguageEnglishUK,
    WPLanguageGerman,
	WPLanguageFrench,
	WPLanguageSpanish,
    WPLanguagePortuguese,
    WPLanguageBrazilian,
	WPLanguageItalian,
    WPLanguageDutch,
	WPLanguageDanish,
    WPLanguageSwedish,
	WPLanguageNorwegian,
	WPLanguageFinnish,
    WPLanguageIndonesian,
	WPLanguageMedicalUS,
	WPLanguageMedicalUK,
} WPLanguage;

#define USERDATA_DICTIONARY		0x0004
#define USERDATA_AUTOCORRECTOR	0x0001
#define USERDATA_LEARNER		0x0002
#define USERDATA_ALL			0x00FF


@interface LanguageManager : NSObject
{
@private
	WPLanguage	currentLanguage;
	UITextChecker *	textChecker;
}

+ (LanguageManager *) sharedManager;

- (NSString *) languageName:(WPLanguage)wplanguage;
- (NSArray *) spellCheckWord:(NSString *)strWord complete:(Boolean)complete;
- (NSString *) mainDictionaryPath;
- (NSString *) languageCode;
- (NSString *) infoPasteboardName;
- (int) getLanguageID;
- (void) changeCurrentLanguageID:(int)languageID;
- (void) changeCurrentLanguage:(WPLanguage)language;
- (NSRange) badWordRange:(NSString *)str;
- (BOOL) spellCheckerEnabled;
- (NSArray *) supportedLanguages;
- (UIImage *) languageImage;
- (NSString *) userFilePathOfType:(NSInteger)type;
- (WPLanguage) systemLanguage;
- (NSString *) shortLanguageName;
- (NSArray *) supportedLocalLanguages;

- (UIImage *) languageImageForLanguageID:(WPLanguage)languageID;
- (WPLanguage) languageFromLanguageID:(int)languageID;

@property (nonatomic,readonly) WPLanguage	currentLanguage;

@end
