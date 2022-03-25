import 'package:flutter/material.dart';
import 'package:dots_indicator/dots_indicator.dart';
import 'package:introduction_screen/introduction_screen.dart';


void main()
{
  runApp(const MaterialApp(home: MyApp()));
}

class MyApp extends StatelessWidget
{
  const MyApp({Key? key})  : super(key: key);


  @override
  Widget build(BuildContext context)
  {
    return MaterialApp(
      home : IntroPage(),
      );
  }
}

class IntroPage extends StatelessWidget
{
  void Welcomepage(context)
  {
    Navigator.pop(context);
    Navigator.of(context).push(MaterialPageRoute(builder: (_) => HomeScreen()));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: IntroductionScreen(
        globalBackgroundColor: const Color(0xffd6cbc7),
        pages: ListPagesViewModel(),
        onDone: (){
          Welcomepage(context);
        },
        showSkipButton: true,
        skip: const Text('Skip'),
        showNextButton: true,
        next: const Text('Next'),
        done: const Text("Get Started",
          style: TextStyle(fontWeight: FontWeight.w600)),
        dotsDecorator: DotsDecorator(
          size: const Size.square(10.0),
          activeSize: const Size(20.0,10.0),
          color: Colors.black38,
          spacing: const EdgeInsets.symmetric(horizontal: 3.0),
          activeShape: RoundedRectangleBorder(
            borderRadius: BorderRadius.circular(25.0))),
        ),
      );
  }

  List<PageViewModel> ListPagesViewModel() {
    return[
      PageViewModel(
          image: Center(
            child: Image.asset('images/page1.png'),
          ),
        title: 'YOGA SURGE',
        body: 'Welcome to Yoga World',
        footer: const Text('Inhale the future, Exhale the Past'),
        decoration: const PageDecoration(
        )),
        PageViewModel(
    image: Center(
    child: Image.asset("images/page2.png"),
    ),
    title: 'Healthy Freak Exercises',
    body: 'Letting Go is the Hardest Part',
    decoration: const PageDecoration(
    )),

  PageViewModel(
    image: Center(
    child: Image.asset("images/page3.png"),
    ),
    title: 'Cycling',
    body: 'You cannot always control what goes on outside. But you can always control what goes on inside.',
    decoration: const PageDecoration(
    )),

    PageViewModel(
    image: Center(
    child: Image.asset("images/page4.png"),
    ),
    title: 'Meditation',
    body: 'The longest journey of any person is the journey inwards.',
    decoration: const PageDecoration(
        ))

    ];
  }
}

class HomeScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(title: const Text('Welcome'), backgroundColor: const Color(0xffd6cbc7),),
        body: Row(
            mainAxisSize: MainAxisSize.max,
            children: <Widget>[
              Column(
                // crossAxisAlignment: CrossAxisAlignment.end,
                  children: <Widget>[
                    Image.asset('images/welcome.png'),
                    const Text('Yash Katyan', textScaleFactor: 2),
                    const Text(
                      'A optimistic person who believes in '
                          'dreaming big',
                      textScaleFactor: 1,
                    )
                  ])
            ]));
  }
}



