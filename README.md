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

### 内容物 ###
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_contents.JPG" alt="MenZ-TONE内容物">
<br>

|名前|個数|備考|
|:---:|:---:|:---:|
|基板|1|MenZ-TONE専用|
|ATmega328P|1|MenZ-TONE書き込み済み|
|水晶発振子|1|16MHz|
|セラミックコンデンサ|2|22pF|
|セラミックコンデンサ|1|0.1uF|
|電解コンデンサ|1|47uF|
|抵抗|1|330Ω|
|抵抗|4|10kΩ|
|抵抗|8|7セグLEDによって抵抗値変更|
|タクトスイッチ(大)|1|演奏用|
|タクトスイッチ(小)|3|その他操作用|
|発光ダイオード|1|PIN13用|
|発光ダイオード|1|演奏スイッチ用|
|7セグメントLED|1|アノードコモン|
|圧電ブザー|1||

<br clear="all">

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

#### MIDIからMMLに変換する ####

1. 3ML EDITOR 2でMIDIファイルを開きます

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_3mleditor.jpg" width="400px" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_openmidi.jpg" width="400px">

3. MIDIファイルで開くトラックを選択します

   気になる人以外はこのままOKを押してください

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TOME_midiconfig.jpg" width="400px">

4. Tempoの部分にある数字をメモっておきます

   例では100となっています

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_tempo.jpg" width="400px">

5. メロディ部分のスコアを開き、必要な部分だけ切り取ります

   例では3小節途中で切りました

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_score.jpg" width="400px" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_trimscore.jpg" width="400px">
<br>


6. テンポを追加し、MenZ-TONEで読み込ませるためにコメントや改行を削除し1行にします

   テンポは100なので、MMLの先頭にt100を書きます
   1行にしたものをこのあとの作業に使用しますので、メモっておきます

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TOME_addtempo.jpg" width="400px">

<br clear="all">

#### MMLからMenZ-TONEの形式に変換する ####

1. 3ML EDITOR 2で仕込んだMMLをMML2TONEのテキストボックスに入れてconvert!ボタンを押します

   以下の3つの情報がでてきますので、これをこのあとの作業に使います。

   1. テンポ
   2. 配列形式の楽譜
   3. 配列形式の音符の長さ

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_mml3tone.png">

<br clear="all">

#### 曲をプログラムに追加する ####

例では、song2.hの1曲目を変更します。

1. ヘッダファイルを開きます

2. 楽譜を置き換えます（左：変更前、右：変更後）

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_scorecode.png" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_scorecode_change.png">

3. テンポを置き換えます（左：変更前、右：変更後）

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/eb2721cc86852d9137bde1473b83cffd58a12677/photo/MenZ-TONE_tempo.png" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/eb2721cc86852d9137bde1473b83cffd58a12677/photo/MenZ-TONE_tempo_change.png">
<br>

4. 音符の長さを置き換えます（左：変更前、右：変更後）

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_length.png" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/8e4a96d7174a7a30811a7478213c7fccfa547603/photo/MenZ-TONE_length_change.png">

<br clear="all">

#### プログラムを書き込み、曲を確認する ####

---

**この作業はArduinoやMenZ-TONEの故障につながる可能性があります**
<br>
**自己の責任において作業を行ってください**

---

1. ArduinoとMenZ-TONEからAVRを外す

   ソケットとAVRの間にマイナスドライバを差し込み、少し持ち上げます。<br>
   これをAVR両端で交互に行い、徐々にAVRを持ち上げソケットから外します。<br>
   ソケットからAVRを外すときは、足を曲げないように注意しながら外してください。<br>

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_remove1.JPG" width="20%" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_remove2.JPG" width="20%" align="left">
<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_remove3.JPG" width="20%">

2. MenZ-TONEから外したAVRをArudinoに取り付ける

   逆差しをしないよう、ICソケットとAVRの切り欠きを確認して差し込みます。<br>
   外すときのことを考え、最後まで刺さずに軽く浮かせておくと良いでしょう。<br>

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_attachavr.JPG" width="30%">

3. プログラムを書き込む

   いつものようにプログラムを書き込みましょう。

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_writecode.JPG" width="30%">

4. 動作確認

   Arduinoに取り付けたAVRをMenZ-TONEに戻して動作を確認します。
   このときも、ICソケットの切り欠きとAVRの切り欠きの位置を十分注意して差し込みましょう。

<img src="https://raw.githubusercontent.com/The-MenZ/MenZ-TONE/master/photo/MenZ-TONE_run.JPG" width="30%">

<br clear="all">

### 参考URL ###

* [Wikipedia - Music Macro Language](https://ja.wikipedia.org/wiki/Music_Macro_Language)
   - とりあえず基礎的なことを学びましょう
* [マビノギ MML作曲ツール 3ML EDITOR 2 Webpage](http://3ml.jp/)
   - かなりお世話になっているツールですこれがないと始まりません

### どうやって連絡すれば良い？ ###

* http://www.the-menz.com/contact.html
