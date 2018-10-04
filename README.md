# learn-git-together
Let's do some basic GIT stuff.

## What this is and how it works
We're going to make a simple program together to help you guys learn git, github, C, and our development environment.

## What you need
At this point, you should have the following downloaded and ready-to-use:
- git (and optionally, your favorite git gui like the one produced by Github)
- gcc (The GNU C Compiler, either in an IDE or from the command line)
- make (You probably got it with gcc for use on the command line, and it may be in your IDE)

You'll also need a github account.

## Getting started
### Clone the repo
You'll need to have your own copy of this repository on your computer that you can work on: this is done by `cloning` the repository. From the command line:
```
git clone https://github.com/WIT-IEEE-Nugget-Industries-2019/learn-git-together.git
```

If you're using a GUI tool, find a button that says "clone" and follow those instructions. 

You now have a copy of the repository on your computer you can work with!

### Choose a task to solve
Look at the source code and you'll find "stubs". These are functions that should do something, but aren't done yet. Here's an example:

```
/**
 * Finds a to the b power.
 * @param b   The base of the exponent (int)
 * @param e   The exponent (int)
 * @return    b to the e power (int)
 */
int pow(int b, int e) {
    return 0;
}
```

Notice the comment up in the top that describes what's supposed to happen here. It's using the JavaDoc format to tell you that this is a function that "Finds a to the b power", that it takes a parameter `b` to be the base, the parameter `e` to be the exponent, and returns b to the e. Right now, it's empty (except for returning 0 to keep the compiler happy).

Your job (if this is your function) is to take this function and make it do what the comment says it does. Once you've found the function you want to work on, let's move the next step!

### Claim this task
You don't want someone to work on the same thing you're working on because one of you could be doing work elsewhere. To keep things coordinated, we'll be using a project board- find it under the "Projects" tab of this repositor when view online. Claim the task by moving the associated card from "To Do" to "In Progress". Be sure to add your name to the card so we know who's working on it!

### Make sure you're up to date
Every so often, you'll want to `git pull` to make sure that you have the most recent copy of everything. Since we're about to make some changes to the code, this seems like a good time.

### Make a new branch
To keep everything clean, we'll want to make a new branch. This way we can mess with our own things and if it breaks everything, that's OK. With branches, you can feel free to try something a little crazy and not worry about breaking anyone else's stuff.

From the command line:
```
git branch mybranch
```

Make sure to pick a name that's more descriptive than 'mybranch': for example, if you're writing the pow function on this branch, call it 'make-pow-function' or something. Now that you've made a new branch, we need to move over to it so that our edits happen there. Do that with the `checkout` operation:

```
git checkout mybranch
```

Now you're ready to start coding!

### Do the code thing
Write code that meets the criteria. Because it's C, we'll use GCC to compile our C code. However, there's all kinds of options that can make that tricky, so we're going to use 'make' to do that for us.

From the directory where you have the repository installed:
```
make
```

That should either 1) compile correctly, or 2) complain about your code being broken. If it isn't either of those things, check that make was properly installed and that you're in the right directory. Also feel free to ask!

### Test your code
You could test your code by hand, or we could make your life easier by automating that. I've set it up using a library called `munit`, and automated it thanks to make. Just run `make test`.

### Status, Add, and Commit
If you're using a gui, it should display for you what files have changed and what is/isn't being tracked. You can check that on the command line with `git status`. Either way, you should see that `ourlib.c` isn't being tracked right now. We need to tell Git that that's what we want by adding it to the staging area. This can either be done with 
```
git add ourlib.c
```

or, in the case of the gui, probably dragging and dropping it to the staging area.

Once the file is the way you like it, you can make a commit. A commit saves the state of the file in history, so we can go back to it later or, more importantly, share it with everyone else. By running
```
git commit -m "Git message here"
```

we commit everything that we added. The `-m "Git message here"` is how you title your commit. Commits need to be titled.

You can add and commit as many times as you want on your own machine. At some point, however, you'll want to share it with everyone else.

### Sharing your code with everyone else
Make sure that you have commits ready to go, and then push your code to the server with
```
git push
```
Sometimes it complains about there being no 'upstream'. This happens when you create a branch the server doesn't know about, so just type in the command it recommends and you'll be fine.

After typing `git push`, it will ask for your username and password (the first time you run git it may need other info, too). Give them that and you should be all set!

### Merging and Merge Requesting
So you've shared code online, but it's still not in the master branch. The master branch is the branch of code we must always keep clean and working a perfect, so once you're happy with your code, request a merge through the Github website. I (Chris) will get notified, we can review it, and then put it through.

## That's that!
I know it looks a bit daunting, but once you get used to it it becomes really easy and intuitive. When we start to make more complicated stuff, you'll start to get an idea of why this is so useful and why it's used in industry all the time.

