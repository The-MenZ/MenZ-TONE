# MenZ-TONE #
***

|初心者工作|お手軽演奏|ポータブル|
|:---:|:---:|:---:|
|6歳児用知育セット並！|指一本残ってればOK！|ポケットサイズ！|

[![IMAGE ALT TEXT](http://img.youtube.com/vi/f3aGDDzvwAQ/0.jpg)](http://www.youtube.com/watch?v=f3aGDDzvwAQ "Youtube video")

### これは何？ ###
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_real.jpg" width="50%" align="right" alt="MenZ-TONE実物">
世界最小の音ゲーマシン！<br>
ボタン一つに、圧電ブザー、スコアは自分の満足感！<br>
楽器が何もできないのに、音楽を演奏したいヤツ必見！<br>
指一本残ってれば演奏できるぞ！<br>

<br clear="all">

### 特徴 ###
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_circuit.png" width="50%" align="right" alt="MenZ-TONE回路図">
1鍵盤だけで曲を奏でる！<br>
それっぽいタイミングでキーを押していけば Arduino が勝手に演奏！<br>

<br clear="all">

### どうやって作るの？ ###

###### 1. 必要なハードウェアを揃えましょう  

|名前|型番|
|:---:|:---:|
|Arduino|UNO R3|
|ブレッドボード|-|
|圧電スピーカー|-|
|タクトスイッチ|-|
|抵抗|100Ω|
|抵抗|10kΩ|
|リード線|5本くらい|

###### 2.回路図の通りにパーツを接続します</dt>
![](photo/MenZ-TONE.png)

###### 3. Arduinoにプログラムファイルを書き込み、タクトスイッチを押して見ましょう！

### 他の曲は無いの？ ###
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_kit.jpg" width="50%" align="right" alt="MenZ-TONE回路図">
MMLデータをMenZ-TONE用のデータにコンバートするツールを作りました<br>
http://www.the-menz.com/mml2tone.html <br>
 <br>
songs.hに自動演奏データや曲データが入っています<br>
これを書き換えてArduinoに書き込みましょう<br>
 <br>
MIDI -> MML -> TONE の流れでMIDIからTONEに自動演奏&曲データを流し込めます<br>
 <br>
MIDIからMMLに変換するには 3ML EDITOR 2 が便利です<br>
http://3ml.jp/

<br clear="all">

### どうやって連絡すれば良い？ ###

* http://www.the-menz.com/contact.html
