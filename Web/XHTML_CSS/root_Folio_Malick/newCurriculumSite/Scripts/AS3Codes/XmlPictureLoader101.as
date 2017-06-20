﻿package Scripts.AS3Codes {		// ******** HOW IT WORKS ****************	// 8 images have been uploaded from an XML file, 	// An XMLList has been used as an Array to hold all the 8 images.	// When loading is complete, a first Timer will fire up every 2 seconds to load an image from the XMLList,	// Within the Event handler of that Timer, a second Timer will enter into action once every second.	// Within the Event handler of the latter Timer, 3 classes that were imported previously, 	// And instantiated before being inserted into 2 different Arrays (one for the classes and one for their instances),	// Will be used sequentially 8 times to mask the images with their animation effects (that's why you created the Arrays).	// And lastly all objects in the Display List have been added to a main container 	// for a quick removal at the end of the animation to clear up some memory.		import flash.display.MovieClip;	import flash.display.Sprite;	import flash.xml.XMLDocument;	import flash.events.Event;	import flash.net.URLRequest;	import flash.net.URLLoader;	import flash.display.Loader;	import flash.utils.Timer;	import flash.events.TimerEvent;	public class XmlPictureLoader101 extends MovieClip {		private var xmlReq:URLRequest;		private var myURLLoader:URLLoader;		private var xmlData:XML;		private var xmlArray:XMLList;		private var imgLoader:Loader;				// Create counter for XMLList		private var counter:Number = 0;				// create a main container		private var myContainer:Sprite;				// Create objects from the 3 BillBoard classes that will act as animated masks.		private var _billBoard1:BillBoard1;		private var _billBoard2:BillBoard2;		private var _billBoard3:BillBoard3;				// Create an Array to hold all animated masks (the imported classes).		private var maskArray:Array;		// Create an Array to hold their new instances.		private var objectArray:Array;		// Create an index counter		private var _Index:int = 0;		// TIMERS		private var myTimer:Timer = new Timer(2000, 8);		private var myTimer1:Timer = new Timer(1000, 1);		// This Timer has to wait for "myTimer" to finish (2000 * 8) before firing up and 		// removing all the items on the stage except the top image and its mask.		private var endTimer:Timer = new Timer(16000, 1);						public function XmlPictureLoader101() {			// You have to specify the exact path to the file location RELATIVE TO THE MAIN FLA FILE.			xmlReq = new URLRequest("Scripts/AS3Codes/albumPictures.xml");			xmlArray = new XMLList;			myURLLoader = new URLLoader;						myURLLoader.load(xmlReq);						myURLLoader.addEventListener(Event.COMPLETE, onComplete);						// Instantiate main container			myContainer = new Sprite;			addChild(myContainer);						// ORGANIZE THE CLASSES AND THEIR INSTANCES IN 2 DIFFERENT ARRAYS;			// First instantiate the mask Array, and populate it with the 3 classes.			maskArray = new Array();			maskArray[0] = BillBoard1;			maskArray[1] = BillBoard2;			maskArray[2] = BillBoard3;						// Second instantiate the second Array and populate it with the 3 instances of the classes.			objectArray = new Array();			objectArray[0] = _billBoard1;			objectArray[1] = _billBoard2;			objectArray[2] = _billBoard3;			// "objectArray[_Index] = new maskArray[_Index]", is the SAME as " _billBoard1 = new BillBoard1 ";			// You will use this Formula while updating the counter to loop through the various classes. 		}				private function onComplete(myEvent:Event):void {			// Load the xml data and put it in an XMLList which is an Array			xmlData = new XML(myURLLoader.data);			xmlArray = xmlData.children();						// Run the first Timer to load an image every 2 seconds.			myTimer.addEventListener(TimerEvent.TIMER, slideShow);			myTimer.start();		}				private function slideShow(myEvent:TimerEvent):void {			// You have to create a new Loader for each image if you want to display them all			// Remember a Loader can hold only one content, so in this case you'll need multiple Loaders.			imgLoader = new Loader;			imgLoader.load(new URLRequest(xmlArray[counter].attribute("source")));			// Update the XMLList counter			counter++;						// In order to clean the mask objects spread on the stage by _billBoard1,			// you use "removeChildAt()" in the "maskDisplay" Function,			// But the problem is that if you use that method at the bottom of the function -after displaying the objects-			// It won't work, so you must use it before displaying the mask and masked objects,			// Another problem is that you have to mask something initially, before the first "removeChildAt()" iteration,			// otherwise Errors will be thrown; that's why you created "mySprite" here and masked it.			objectArray[_Index] = new maskArray[_Index];			myContainer.addChild(objectArray[_Index]);			var mySprite:Sprite = new Sprite;			mySprite.mask = objectArray[_Index];						// An image is loaded every 2 seconds, so after the first second of each loaded image, 			// This second Timer will fire up once, instantiating each time one of the imported classes,			// That are holding some transition effect masking the image.			myTimer1.addEventListener(TimerEvent.TIMER, maskDisplay);			myTimer1.start();		}				function maskDisplay(newEvent:TimerEvent):void {			// Remove the imported class with all its mask objects before apply them again			// OBSERVE THE SYNTAX HERE			myContainer.removeChildAt(myContainer.getChildIndex(objectArray[_Index]));			// Instantiate a new BillBoard class -that is the mask- again.			objectArray[_Index] = new maskArray[_Index];			myContainer.addChild(objectArray[_Index]);			// Now add the Loader to the stage and mask it with the imported  _billBoard1.			myContainer.addChild(imgLoader);			imgLoader.mask = objectArray[_Index];						// Update the animated masks counter			_Index++;			if(_Index >= objectArray.length) {				_Index = 0;			}						// This Timer will remove all the objects on the stage except 2.			endTimer.addEventListener(TimerEvent.TIMER, removeSomeImages);			endTimer.start();		}				private function removeSomeImages(myEvent:TimerEvent):void {			//trace(myContainer.numChildren);			// Remove all contents of the main container except the top image and its mask (Look at the syntax);			for(var i:Number = 0; i = myContainer.numChildren - 2; i++) {				// Always remove children from the bottom				myContainer.removeChildAt(0);			}						endTimer.removeEventListener(TimerEvent.TIMER, removeSomeImages);			//trace(myContainer.numChildren);		}			}}